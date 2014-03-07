#include "InitializeController.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

InitializeController::InitializeController(void)
{
    
}


InitializeController::~InitializeController(void)
{
    CCLOG("InitializeController destroy");
}

void InitializeController::viewDidLoad()
{
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("start", "Arial", 20),
                                                      this,
                                                      menu_selector(InitializeController::startGameCallback));
    startGameItem->setPosition(ccp(screenSize.width-100,screenSize.height/2));
    
    CCMenuItemLabel *buildItem=CCMenuItemLabel::create(CCLabelTTF::create("build", "Arial", 20),
                                                           this,
                                                           menu_selector(InitializeController::buildCallback));
    buildItem->setPosition(ccp(screenSize.width-200,screenSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem, buildItem,NULL);
    menu->setPosition( CCPointZero );
    
    m_view->addChild(menu);

}

void InitializeController::startGameCallback(CCObject* pSender)
{
    cocos2d::mygame::GameSceneDirector::getInstance()->replaceScene(kMainScene);
}

void InitializeController::buildCallback(CCObject* pSender)
{
    cocos2d::mygame::GameSceneDirector::getInstance()->pushScene(kBuildMainScene);
}

NS_MYGAME_END