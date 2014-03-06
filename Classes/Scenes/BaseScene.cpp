//
//  BaseScene.cpp
//  CCUI
//
//  Created by duanhouhai on 13-8-6.
//
//

#include "BaseScene.h"

USING_NS_CC;

NS_MYGAME_BEGIN

BaseScene::BaseScene()
:m_document(NULL)
,m_internalOrgnaizer(NULL)
{
    
}

BaseScene::~BaseScene()
{
    //    CC_SAFE_RELEASE_NULL(m_document);
    CC_SAFE_RELEASE_NULL(m_internalOrgnaizer);
}

bool BaseScene::init()
{
    if(yhmvc::Scene::init()){
        
        createDocument();
        return true;
    }
    
    return false;
}

void BaseScene::createDocument()
{
    m_internalOrgnaizer=new yhgui::NormalDocumentTreeOrganizer();
    m_internalOrgnaizer->init();
    m_internalOrgnaizer->registerWithTouchDispatcher();
    
    m_document=new yhgui::Component();
    
    addChild(m_document);
    
    m_internalOrgnaizer->setDocument(m_document);
    
    m_document->release();
}

// on "init" you need to initialize your instance
void BaseScene::loadContents()
{
    yhmvc::Scene::loadContents();
//    createDocument();
    
}

NS_MYGAME_END
