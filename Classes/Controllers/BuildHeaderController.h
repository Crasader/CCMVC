#ifndef CCMVC_CONTROLLERS_BUILDHEADERCONTROLLER_H_
#define CCMVC_CONTROLLERS_BUILDHEADERCONTROLLER_H_

#include <yhmvc/yhmvc.h>
#include "BaseController.h"
#include "../SceneBuilder/BuilderDefine.h"

NS_MYGAME_BEGIN

class BuildHeaderController:public BaseController
{
public:
	
    BuildHeaderController(void);
    
	~BuildHeaderController(void);

	void viewDidLoad();
    
    CREATE_FUNC(BuildHeaderController);
};

GAME_CONTROLLER_CREATOR(BuildHeaderController);

NS_MYGAME_END

#endif //CCMVC_CONTROLLERS_BUILDHEADERCONTROLLER_H_
