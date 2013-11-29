#include "InitializeController.h"
#include "mvc/Layer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

InitializeController::InitializeController(void)
{
    
}


InitializeController::~InitializeController(void)
{
    
}

void InitializeController::loadLayer()
{
	yhmvc::Layer* layer=new yhmvc::Layer();
    layer->init();
    
	setLayer(layer);
	layer->release();
    
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    CCMenuItemLabel *startGameItem=CCMenuItemLabel::create(CCLabelTTF::create("start", "Arial", 20),
                                                      this,
                                                      menu_selector(InitializeController::startGameCallback));
    startGameItem->setPosition(ccp(screenSize.width-100,screenSize.height/2));
    
    CCMenu* menu=CCMenu::create(startGameItem, NULL);
    menu->setPosition( CCPointZero );
    
    layer->addChild(menu);

}

void InitializeController::startGameCallback(CCObject* pSender)
{
    cocos2d::mygame::GameSceneDirector::getInstance()->replaceScene(kMainScene);
}

NS_MYGAME_END