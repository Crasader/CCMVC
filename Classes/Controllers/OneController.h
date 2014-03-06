#ifndef __HELLOWORLD_OneController_H__
#define __HELLOWORLD_OneController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN

/**
 * 单独的。
 * 由Scene来组合controller。
 * 可以添加其它controller来作为显示内容
 * 由于结构简单不容易出错。
 */
class OneController:public cocos2d::yhmvc::Controller
{
public:
	
    OneController(void);
    
	~OneController(void);

	void viewDidLoad();

	void backCallback(cocos2d::CCObject* pSender);
    
    void nextCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_OneController_H__