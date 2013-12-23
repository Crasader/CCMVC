#include "TwoController.h"
#include "yhmvc/Core/Layer.h"
#include "Scenes/GameSceneDirector.h"
#include "ThreeSegmentController.h"
#include "HeaderController.h"
#include "FooterController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

TwoController::TwoController(void)
{
    
}


TwoController::~TwoController(void)
{
    CCLOG("TwoController destroy");
}

void TwoController::layerDidLoad()
{
    ThreeSegmentController* threeSegmentController=new ThreeSegmentController();
    threeSegmentController->init();
    this->addChildLayerController(threeSegmentController);
    threeSegmentController->release();
    
    m_layer->addChild(threeSegmentController->getLayer());
    
    
    HeaderController* headerController=new HeaderController();
    headerController->init();
    this->addChildLayerController(headerController);
    headerController->release();
    headerController->setPreferredContentSize(threeSegmentController->getHeaderLayer()->getContentSize());
    threeSegmentController->getHeaderLayer()->addChild(headerController->getLayer());
    
    FooterController* footerController=new FooterController();
    footerController->init();
    this->addChildLayerController(footerController);
    footerController->release();
    footerController->setPreferredContentSize(threeSegmentController->getFooterLayer()->getContentSize());
    threeSegmentController->getFooterLayer()->addChild(footerController->getLayer());
    
    
    CCSize contentSize=threeSegmentController->getBodyLayer()->getContentSize();
    CCLabelTTF* label= CCLabelTTF::create("two scene", "Arial", 20);
    label->setPosition(ccp(contentSize.width/2,contentSize.height/2));
    threeSegmentController->getBodyLayer()->addChild(label);
    
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 20),
                                                           this,
                                                           menu_selector(TwoController::backCallback));
    startGameItem->setPosition(ccp(contentSize.width-200,contentSize.height/2));
    
    
    CCMenuItemLabel *next=CCMenuItemLabel::create(CCLabelTTF::create("next", "Arial", 20),
                                                  this,
                                                  menu_selector(TwoController::nextCallback));
    next->setPosition(ccp(contentSize.width-100,contentSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem,next, NULL);
    menu->setPosition( CCPointZero );
    
    threeSegmentController->getBodyLayer()->addChild(menu);
}

void TwoController::backCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->popScene();
}

void TwoController::nextCallback(CCObject* pSender)
{
    GameSceneDirector::getInstance()->replaceScene(kThreeScene);
}

NS_MYGAME_END