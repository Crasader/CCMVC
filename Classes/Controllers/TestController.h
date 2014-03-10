#ifndef __HELLOWORLD_TestController_H__
#define __HELLOWORLD_TestController_H__

#include "BaseController.h"

NS_MYGAME_BEGIN

class TestController:public BaseController
{
public:
	
    TestController(void);
    
	~TestController(void);

	void viewDidLoad();
    
    CREATE_FUNC(TestController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_TestController_H__
