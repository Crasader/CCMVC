#ifndef __HELLOWORLD_BuildOneController_H__
#define __HELLOWORLD_BuildOneController_H__

#include "BaseController.h"

NS_MYGAME_BEGIN

class BuildOneController:public BaseController
{
public:
	
    BuildOneController(void);
    
	~BuildOneController(void);

	void viewDidLoad();
    
    CREATE_FUNC(BuildOneController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_BuildOneController_H__
