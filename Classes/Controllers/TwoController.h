#ifndef __HELLOWORLD_TwoController_H__
#define __HELLOWORLD_TwoController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN

class TwoController:public cocos2d::yhmvc::Controller
{
public:
	
    TwoController(void);
    
	~TwoController(void);

	void viewDidLoad();

	void backCallback(cocos2d::CCObject* pSender);
    
    void nextCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_TwoController_H__
