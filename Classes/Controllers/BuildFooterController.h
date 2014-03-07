#ifndef CCMVC_CONTROLLERS_BUILDFOOTERCONTROLLER_H_
#define CCMVC_CONTROLLERS_BUILDFOOTERCONTROLLER_H_

#include <yhmvc/yhmvc.h>
#include "BaseController.h"
#include "../SceneBuilder/BuilderDefine.h"

NS_MYGAME_BEGIN

class BuildFooterController:public BaseController
{
public:
	
    BuildFooterController(void);
    
	~BuildFooterController(void);

	void onBack(yhge::Event* event);
    
    void onHome(yhge::Event* event);
    
    /**
     * @brief 创建事件管理器
     */
    yhgui::ElementEventParser* createEventParser();
    
    CREATE_FUNC(BuildFooterController);
};

GAME_CONTROLLER_CREATOR(BuildFooterController);

NS_MYGAME_END

#endif //CCMVC_CONTROLLERS_BUILDFOOTERCONTROLLER_H_
