#ifndef CCMVC_SCENEBUILDER_BUILDEREXTERNAL_H_
#define CCMVC_SCENEBUILDER_BUILDEREXTERNAL_H_

#include "cocos2d.h"
#include "GameMacros.h"
#include <yhgui/yhgui.h>
#include <yhmvc/yhmvc.h>
#include "../Scenes/BaseScene.h"
#include "../Controllers/MainController.h"
#include "../Controllers/FooterController.h"
#include "../Controllers/HeaderController.h"
#include "../Controllers/OneController.h"

NS_MYGAME_BEGIN

//==============BaseScene==============//
/**
 * @brief BaseScene 结点创建
 */
class BaseSceneCreator:public yhgui::ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(BaseScene);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BaseSceneCreator,creator);
};

/**
 * @brief BaseScene的子控制器属性处理
 */
class BaseSceneControllerPropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BaseSceneControllerPropertyParser,create);
};

/**
 * @brief BaseScene的处理器
 */
class BaseSceneParser:public yhgui::NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(BaseSceneParser,create);
};

//==============Controller==============//

/**
 * @brief BaseController创建器，不直接使用。是父类
 */
class BaseControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    //virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent);
    
    YHMVC_BUILDER_CREATE_CONTROLLER(BaseController);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BaseControllerCreator,creator);
    
protected:
    
    //virtual yhmvc::View* loadView(BaseController* controller,const yhge::Json::Value& defineData,CCNode* parent,yhgui::UIBuilder* builder);
    //由于ControllerCreator使用的是Controller这里不能使用BaseController,否则虚数就没有效果
    virtual yhmvc::View* loadView(yhmvc::Controller* controller,const yhge::Json::Value& defineData,CCNode* parent,yhgui::UIBuilder* builder);
};

/**
 * @brief MainController 结点创建
 */
class MainControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    YHMVC_BUILDER_CREATE_CONTROLLER(MainController);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainControllerCreator,creator);
};

/**
 * @brief HeaderController 结点创建
 */
class HeaderControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    YHMVC_BUILDER_CREATE_CONTROLLER(HeaderController);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeaderControllerCreator,creator);
};

/**
 * @brief FooterController 结点创建
 */
class FooterControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    YHMVC_BUILDER_CREATE_CONTROLLER(FooterController);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FooterControllerCreator,creator);
};

/**
 * @brief BaseScene 结点创建
 */
class OneControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    YHMVC_BUILDER_CREATE_CONTROLLER(OneController);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OneControllerCreator,creator);
};

NS_MYGAME_END



#endif // CCMVC_SCENEBUILDER_BUILDEREXTERNAL_H_
