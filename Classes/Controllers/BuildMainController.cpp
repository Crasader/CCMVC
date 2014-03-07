#include "BuildMainController.h"
#include "Layers/HelloLayer.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

BuildMainController::BuildMainController(void)
{

}

BuildMainController::~BuildMainController(void)
{
    CCLOG("BuildMainController destroy");
}

void BuildMainController::onGotoBuild(yhge::Event* event)
{
    GameSceneDirector::getInstance()->replaceScene(kBuildScene);
}

void BuildMainController::onGotoTestA(yhge::Event* event)
{
    GameSceneDirector::getInstance()->replaceScene(kTestAScene);
}

yhgui::ElementEventParser* BuildMainController::createEventParser()
{
    yhgui::ElementEventParser* elementEventParser=BaseController::createEventParser();
    
    elementEventParser->addEventHandle("build", this, YH_EVENT_SELECTOR(BuildMainController::onGotoBuild));
    elementEventParser->addEventHandle("testa", this, YH_EVENT_SELECTOR(BuildMainController::onGotoTestA));
    
    return elementEventParser;
}

NS_MYGAME_END