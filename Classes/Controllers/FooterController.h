#ifndef __HELLOWORLD_FooterController_H__
#define __HELLOWORLD_FooterController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN
class FooterController:public cocos2d::yhmvc::Controller
{
public:
	
    FooterController(void);
    
	~FooterController(void);

	void viewDidLoad();

	void homeCallback(cocos2d::CCObject* pSender);
    
    void battleCallback(cocos2d::CCObject* pSender);
    
    void helpCallback(cocos2d::CCObject* pSender);
    
    CREATE_FUNC(FooterController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_FooterController_H__
