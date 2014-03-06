#ifndef CCMVC_SCENEBUILDER_BUILDEREXTERNAL_H_
#define CCMVC_SCENEBUILDER_BUILDEREXTERNAL_H_

#include "cocos2d.h"
#include "GameMacros.h"
#include <yhgui/yhgui.h>
#include <yhmvc/yhmvc.h>
#include "../Scenes/BaseScene.h"

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
 * @brief MainController 结点创建
 */
template<class T>
class ControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
    {
        T* controller=new T();
        yhmvc::View* view=createView(defineData[yhgui::kPropertyNameProperties], parent, builder);
        controller->setView(view);
        
        controller->autorelease();
        
        return view;
    }
    
    static ControllerCreator * creator() {
        ControllerCreator * ptr = new T();
        if(ptr != NULL) {
            ptr->autorelease();
            return ptr;
        }
        CC_SAFE_DELETE(ptr);
        return NULL;
    }
};

/**
 * @brief MainController 结点创建
 */
class MainControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainControllerCreator,creator);
};

/**
 * @brief HeaderController 结点创建
 */
class HeaderControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HeaderControllerCreator,creator);
};

/**
 * @brief FooterController 结点创建
 */
class FooterControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FooterControllerCreator,creator);
};

/**
 * @brief BaseScene 结点创建
 */
class OneControllerCreator:public yhmvc::ControllerCreator
{
public:
    
    virtual CCNode * createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OneControllerCreator,creator);
};

NS_MYGAME_END



#endif // CCMVC_SCENEBUILDER_BUILDEREXTERNAL_H_
