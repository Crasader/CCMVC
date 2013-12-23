#ifndef __HELLOWORLD_MainController_H__
#define __HELLOWORLD_MainController_H__

#include "yhmvc/Core/LayerController.h"
#include "yhmvc/Core/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN

class MainController:public cocos2d::yhmvc::LayerController
{
public:
	MainController(void);
	~MainController(void);

	void loadLayer();

	void menuCloseCallback(cocos2d::CCObject* pSender);
    
    void menuRunCallback(cocos2d::CCObject* pSender);
    void menuStopCallback(cocos2d::CCObject* pSender);
    void menuMoveToCallback(cocos2d::CCObject* pSender);
};

NS_MYGAME_END

#endif //__HELLOWORLD_MainController_H__
