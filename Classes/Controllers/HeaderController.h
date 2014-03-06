#ifndef __HELLOWORLD_HeaderController_H__
#define __HELLOWORLD_HeaderController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN
class HeaderController:public cocos2d::yhmvc::Controller
{
public:
	
    HeaderController(void);
    
	~HeaderController(void);

	void viewDidLoad();

	void showUserInfoCallback(cocos2d::CCObject* pSender);
    
    CREATE_FUNC(HeaderController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_HeaderController_H__
