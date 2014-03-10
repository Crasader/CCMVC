#include "TestController.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

TestController::TestController(void)
{
    
}


TestController::~TestController(void)
{
    CCLOG("TestController destroy");
}

void TestController::viewDidLoad()
{    
    CCLOG("TestController::viewDidLoad");
}


NS_MYGAME_END