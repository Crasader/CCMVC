#ifndef __HELLOWORLD_ThreeController_H__
#define __HELLOWORLD_ThreeController_H__

#include "ThreeSegmentController2.h"

NS_MYGAME_BEGIN

/**
 * 直接继承结构化控制器。
 * 容易引起误用。父类的m_view是结构化控制器其它layer的容器。当前类中不能使用m_view。
 */
class ThreeController:public ThreeSegmentController2
{
public:
	
    ThreeController(void);
    
	~ThreeController(void);

	void viewDidLoad();

	void backCallback(cocos2d::CCObject* pSender);
    
    void nextCallback(cocos2d::CCObject* pSender);
    
    CREATE_FUNC(ThreeController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_ThreeController_H__
