#include "BuildFooterController.h"
#include "Scenes/GameSceneDirector.h"
#include <yhgui/yhgui.h>
#include <yhmvc/yhmvc.h>

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

BuildFooterController::BuildFooterController(void)
{
    
}


BuildFooterController::~BuildFooterController(void)
{
    CCLOG("BuildFooterController destroy");
}

void BuildFooterController::onBack(yhge::Event* event)
{
    GameSceneDirector::getInstance()->popScene();
}

void BuildFooterController::onHome(yhge::Event* event)
{
    GameSceneDirector::getInstance()->popToRootScene();
}

yhgui::ElementEventParser* BuildFooterController::createEventParser()
{
    yhgui::ElementEventParser* elementEventParser=BaseController::createEventParser();
    
    elementEventParser->addEventHandle("back", this, YH_EVENT_SELECTOR(BuildFooterController::onBack));
    elementEventParser->addEventHandle("home", this, YH_EVENT_SELECTOR(BuildFooterController::onHome));
    
    return elementEventParser;
}

NS_MYGAME_END