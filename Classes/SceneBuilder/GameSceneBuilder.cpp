
#include "GameSceneBuilder.h"
#include "BuilderExternal.h"
#include "BuilderDefine.h"
#include "../Scenes/GameSceneDirector.h"
#include "../Controllers/TestController.h"
#include "../Controllers/BuildOneController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

static GameSceneBuilder* s_gameSceneBuilderInstance=NULL;

GameSceneBuilder::GameSceneBuilder()
{
    CCLOG("GameSceneBuilder create");
}

GameSceneBuilder::~GameSceneBuilder()
{
    CCLOG("GameSceneBuilder destory");
}

GameSceneBuilder* GameSceneBuilder::getInstance()
{
    if(!s_gameSceneBuilderInstance){
        s_gameSceneBuilderInstance=new GameSceneBuilder();
        s_gameSceneBuilderInstance->init();
    }
    
    return s_gameSceneBuilderInstance;
}

#define GAMESCENEBUILDER_REGISTERCONTROLLER(C)  addController(#C,C##Creator::creator())

#define GAMESCENEBUILDER_REGISTERCONTROLLER_T(C) addController(#C,ControllerCreator< C >::creator())

void GameSceneBuilder::setupExtend()
{
    MvcBuilder::setupExtend();
    
    //controllers creates
    m_elementCreatorFactory->registerElementCreator("MainController", MainControllerCreator::creator());
    m_elementParserFactory->registerElementParser("MainController", ControllerParser::create());
    
    m_elementCreatorFactory->registerElementCreator("FooterController", FooterControllerCreator::creator());
    m_elementParserFactory->registerElementParser("FooterController", ControllerParser::create());
    
    m_elementCreatorFactory->registerElementCreator("HeaderController", HeaderControllerCreator::creator());
    m_elementParserFactory->registerElementParser("HeaderController", ControllerParser::create());
    
    m_elementCreatorFactory->registerElementCreator("OneController", OneControllerCreator::creator());
    m_elementParserFactory->registerElementParser("OneController", ControllerParser::create());
    
    GAMESCENEBUILDER_REGISTERCONTROLLER_T(TestController);

    GAMESCENEBUILDER_REGISTERCONTROLLER_T(BuildOneController);
    
}

void GameSceneBuilder::addController(const std::string& constroller,yhgui::ElementCreator* creator)
{
    m_elementCreatorFactory->registerElementCreator(constroller, creator);
    m_elementParserFactory->registerElementParser(constroller, ControllerParser::create());
}

yhmvc::Controller* GameSceneBuilder::buildScene()
{
    GameSceneBuilder* builder=getInstance();
    
    std::string sceneName=GameSceneDirector::getInstance()->getCurrentSceneName();
    
    yhmvc::View* view= static_cast<yhmvc::View*>(builder->buildWithJSONFile(getSceneDefineFile(sceneName).c_str()));
    
//    builder->release();
    
    return view->getController();
}

std::string GameSceneBuilder::getSceneDefineFile(const std::string& sceneName)
{
    return "ui/"+sceneName+".json";
}

NS_MYGAME_END
