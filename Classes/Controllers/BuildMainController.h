#ifndef __HELLOWORLD_BuildMainController_H__
#define __HELLOWORLD_BuildMainController_H__

#include "BaseController.h"

NS_MYGAME_BEGIN

class BuildMainController:public BaseController
{
public:
	BuildMainController(void);
	~BuildMainController(void);
    
    
    void onGotoBuild(yhge::Event* event);
    
    void onGotoTestA(yhge::Event* event);
    
    /**
     * @brief 创建事件管理器
     */
    yhgui::ElementEventParser* createEventParser();
    
    CREATE_FUNC(BuildMainController);
};

NS_MYGAME_END

#endif //__HELLOWORLD_BuildMainController_H__
