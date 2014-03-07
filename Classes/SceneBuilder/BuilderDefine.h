#ifndef CCMVC_SCENEBUILDER_BUILDERDEFINE_H_
#define CCMVC_SCENEBUILDER_BUILDERDEFINE_H_

#include "cocos2d.h"
#include "GameMacros.h"
#include <yhgui/yhgui.h>
#include <yhmvc/yhmvc.h>
#include "BuilderExternal.h"

NS_MYGAME_BEGIN

/**
 * @brief ControllerCreator template 结点创建
 */
template<class T>
class ControllerCreator:public BaseControllerCreator
{
public:
    
    YHMVC_BUILDER_CREATE_CONTROLLER(T);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ControllerCreator,creator);
};

NS_MYGAME_END

#define GAME_CONTROLLER_CREATOR(C) class C##Creator:public BaseControllerCreator\
{\
public:\
    YHMVC_BUILDER_CREATE_CONTROLLER(C);\
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(C##Creator,creator);\
}

#endif // CCMVC_SCENEBUILDER_BUILDERDEFINE_H_
