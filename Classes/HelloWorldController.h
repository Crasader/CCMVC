#ifndef __HELLOWORLD_HELLOWORLDCONTROLLER_H__
#define __HELLOWORLD_HELLOWORLDCONTROLLER_H__

#include "mvc/YHLayerController.h"

class HelloWorldController:public cocos2d::yhmvc::YHLayerController
{
public:
	HelloWorldController(void);
	~HelloWorldController(void);

	void loadLayer();

	void menuCloseCallback(CCObject* pSender);
    
    void menuRunCallback(CCObject* pSender);
    void menuStopCallback(CCObject* pSender);
    void menuMoveToCallback(CCObject* pSender);
};
#endif //__HELLOWORLD_HELLOWORLDCONTROLLER_H__
