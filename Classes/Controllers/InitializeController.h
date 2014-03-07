#ifndef __HELLOWORLD_InitializeController_H__
#define __HELLOWORLD_InitializeController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN
class InitializeController:public cocos2d::yhmvc::Controller
{
public:
	
    InitializeController(void);
    
	~InitializeController(void);

	void viewDidLoad();

	void startGameCallback(cocos2d::CCObject* pSender);
    
    void buildCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_InitializeController_H__
