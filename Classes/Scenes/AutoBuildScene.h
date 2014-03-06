#ifndef __MAINSCENE_AutoBuildScene_H__
#define __MAINSCENE_AutoBuildScene_H__

#include "cocos2d.h"
#include <yhmvc/yhmvc.h>
#include <yhgui/yhgui.h>
#include "GameMacros.h"


NS_MYGAME_BEGIN

class AutoBuildScene : public yhmvc::Scene
{
public:

    AutoBuildScene();
    
    ~AutoBuildScene();
    
    bool init();
    
    virtual void createDocument();
    
    void loadContents();
    
    inline void setDocument(yhgui::Component* document)
    {
//        CC_SAFE_RETAIN(document);
//        CC_SAFE_RELEASE(m_document);
        m_document = document;
    }
    
    inline yhgui::Component* getDocument()
    {
        return m_document;
    }

public:
    
    CREATE_FUNC(AutoBuildScene);
    
    static std::string getSceneDefineFile(const std::string& sceneName);
    
    static AutoBuildScene* buildScene();
    
    
    
protected:

    yhgui::Component* m_document;
    
    yhgui::NormalDocumentTreeOrganizer* m_internalOrgnaizer;

};




/**
 * @brief scene 结点创建
 */
class AutoBuildSceneCreator:public yhgui::ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(AutoBuildScene);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AutoBuildSceneCreator,creator);
};

/**
 * @brief scene的子控制器属性处理
 */
class AutoBuildSceneControllerPropertyParser:public yhgui::PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AutoBuildSceneControllerPropertyParser,create);
};

/**
 * @brief Scene的处理器
 */
class AutoBuildSceneParser:public yhgui::NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(AutoBuildSceneParser,create);
};



NS_MYGAME_END

#endif // __MAINSCENE_AutoBuildScene_H__
