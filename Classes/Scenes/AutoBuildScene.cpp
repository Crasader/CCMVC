#include "AutoBuildScene.h"
#include "GameSceneDirector.h"

using namespace cocos2d;

USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

AutoBuildScene::AutoBuildScene()
:m_document(NULL)
,m_internalOrgnaizer(NULL)
{
    
}

AutoBuildScene::~AutoBuildScene()
{
//    CC_SAFE_RELEASE_NULL(m_document);
    CC_SAFE_RELEASE_NULL(m_internalOrgnaizer);
}

bool AutoBuildScene::init()
{
    if(yhmvc::Scene::init()){
        
        createDocument();
        return true;
    }
    
    return false;
}

void AutoBuildScene::createDocument()
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
void AutoBuildScene::loadContents()
{
    yhmvc::Scene::loadContents();
    
    createDocument();
    
    
}

AutoBuildScene* AutoBuildScene::buildScene()
{
    MvcBuilder* builder=new MvcBuilder();
    builder->init();
    
    //replace scene create to AutoBuildScene
    
    yhgui::ElementCreatorFactory* elementCreatorFactory=builder->getElementCreatorFactory();
    yhgui::ElementParserFactory* elementParserFactory=builder->getElementParserFactory();
    
    elementCreatorFactory->registerElementCreator(yhmvc::kElementTypeScene, AutoBuildSceneCreator::creator());
    elementParserFactory->registerElementParser(kElementTypeScene, AutoBuildSceneParser::create());
    
    std::string sceneName=GameSceneDirector::getInstance()->getCurrentSceneName();
    
    AutoBuildScene* scene= static_cast<AutoBuildScene*>(builder->buildWithJSONFile(getSceneDefineFile(sceneName).c_str()));
    
    builder->release();
    
    return scene;
}

std::string AutoBuildScene::getSceneDefineFile(const std::string& sceneName)
{
    return "ui/"+sceneName+".json";
}


void AutoBuildSceneControllerPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhge::Json::Value controllersValue=properties[yhmvc::kElementPropertyController];
    if (!controllersValue.isNull()) {
        AutoBuildScene* scene=static_cast<AutoBuildScene*>(node);
        yhmvc::View* view=NULL;
        
        yhge::Json::Value::UInt count=controllersValue.size();
        for (int i=0;i<count;i++) {
            view=static_cast<yhmvc::View*>(builder->buildElement(controllersValue[i],node,false));
            scene->addController(view->getController());
            scene->getDocument()->addChild(view);
        }
    }
}

void AutoBuildSceneParser::setupPropertyParser()
{
    yhgui::NodeParser::setupPropertyParser();
    
    registerPropertyParser(kElementPropertyController, AutoBuildSceneControllerPropertyParser::create());
}


NS_MYGAME_END