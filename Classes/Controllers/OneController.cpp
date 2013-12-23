#include "OneController.h"
#include "yhmvc/Core/Layer.h"
#include "Scenes/GameSceneDirector.h"
#include "HeaderController.h"
#include "FooterController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

OneController::OneController(void)
{
    
}


OneController::~OneController(void)
{
    CCLOG("OneController destroy");
}

void OneController::layerDidLoad()
{
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    float headerHeight=60.0f,footerHeight=64.0f;
    
    float bodyHeight=screenSize.height-headerHeight-footerHeight;
    
    //create header
    HeaderController* headerController=new HeaderController();
    headerController->init();
    this->addChildLayerController(headerController);
    headerController->release();
    headerController->setPreferredContentSize(CCSizeMake(screenSize.width, headerHeight));
    m_layer->addChild(headerController->getLayer());
    headerController->getLayer()->setPosition(ccp(0.0f, screenSize.height-headerHeight));
    
    
    //create footer
    FooterController* footerController=new FooterController();
    footerController->init();
    this->addChildLayerController(footerController);
    footerController->release();
    footerController->setPreferredContentSize(CCSizeMake(screenSize.width,footerHeight));
    m_layer->addChild(footerController->getLayer());
    
    //create body
    yhmvc::Layer* bodyLayer=yhmvc::Layer::create();
    bodyLayer->setContentSize(CCSizeMake(screenSize.width, bodyHeight));
    bodyLayer->setPosition(ccp(0.0f, footerHeight));
    m_layer->addChild(bodyLayer);
    
    
    CCSize contentSize=CCSizeMake(screenSize.width, bodyHeight);
    
    
    CCLabelTTF* label= CCLabelTTF::create("one scene", "Arial", 20);
    label->setPosition(ccp(contentSize.width/2,contentSize.height/2));
    bodyLayer->addChild(label);
    
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 20),
                                                      this,
                                                      menu_selector(OneController::backCallback));
    startGameItem->setPosition(ccp(contentSize.width-200,contentSize.height/2));
    
    
    CCMenuItemLabel *next=CCMenuItemLabel::create(CCLabelTTF::create("next", "Arial", 20),
                                                           this,
                                                           menu_selector(OneController::nextCallback));
    next->setPosition(ccp(contentSize.width-100,contentSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem,next, NULL);
    menu->setPosition( CCPointZero );
    
    bodyLayer->addChild(menu);

}

void OneController::backCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->popScene();
}

void OneController::nextCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kTwoScene);
}

NS_MYGAME_END