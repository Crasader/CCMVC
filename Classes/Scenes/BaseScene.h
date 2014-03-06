//
//  BaseScene.h
//  CCUI
//
//  Created by duanhouhai on 13-8-6.
//
//

#ifndef __CCUI__BaseScene__
#define __CCUI__BaseScene__

#include "cocos2d.h"
#include <yhgui/yhgui.h>
#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN

class BaseScene:public cocos2d::yhmvc::Scene
{
public:
    
    BaseScene();
    
    ~BaseScene();
    
    bool init();
    
    virtual void createDocument();
    
    void loadContents();
    
    CREATE_FUNC(BaseScene);
    
public:
    
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
    
protected:
    
    yhgui::Component* m_document;
    
    yhgui::NormalDocumentTreeOrganizer* m_internalOrgnaizer;
};

NS_MYGAME_END

#endif /* defined(__CCUI__BaseScene__) */
