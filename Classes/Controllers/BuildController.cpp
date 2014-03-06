#include "BuildController.h"
#include "Layers/HelloLayer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

BuildController::BuildController(void)
{

}

BuildController::~BuildController(void)
{
    CCLOG("BuildController destroy");
}

void BuildController::loadViewFromFile()
{
    MvcBuilder* builder=new MvcBuilder();
    builder->init();
    builder->setElementEventParser(createEventParser());
    
    yhmvc::View* view= static_cast<yhmvc::View*>(builder->buildWithJSONFile(m_viewFile.c_str()));
    
    setView(view);
    
    builder->release();
}

void BuildController::onViewEnter()
{
    CCLOG("view enter");
    Controller::onViewEnter();
}

void BuildController::onViewExit()
{
    CCLOG("view exit");
    Controller::onViewExit();
}

void BuildController::onTestA(yhge::Event* event)
{
    CCLOG("onTestA button click");
    GameSceneDirector::getInstance()->popScene();
}

yhgui::ElementEventParser* BuildController::createEventParser()
{
    yhgui::ElementEventParser* eventParser=new yhgui::ElementEventParser();
    eventParser->init();
    eventParser->addEventHandle("testa",this,YH_EVENT_SELECTOR(BuildController::onTestA));
    
    eventParser->autorelease();
    return eventParser;
}

NS_MYGAME_END