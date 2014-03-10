#ifndef CCMVC_SCENES_SCENEREGISTERDATA_H_
#define CCMVC_SCENES_SCENEREGISTERDATA_H_

#include <yhmvc/Controllers/ControllerDirector.h>
#include "GameMacros.h"
#include "SceneDefine.h"

//this file generate by tools.do not modify directorly

#include "Controllers/InitializeController.h"
#include "Controllers/MainController.h"
#include "Controllers/ShopController.h"
#include "Controllers/OneController.h"
#include "Controllers/TwoController.h"
#include "Controllers/ThreeController.h"
#include "SceneBuilder/GameSceneBuilder.h"


NS_MYGAME_BEGIN

typedef struct SceneRegisterItem
{
    std::string name;
    cocos2d::yhmvc::ControllerCreate createFun;
} SceneRegisterItem;

static SceneRegisterItem kSceneRegisterData[]=
{
	{kInitializeScene,CONTROLLER_CREATE_SELECTOR(InitializeController::create)},
	{kMainScene,CONTROLLER_CREATE_SELECTOR(MainController::create)},
	{kShopScene,CONTROLLER_CREATE_SELECTOR(ShopController::create)},
	{kOneScene,CONTROLLER_CREATE_SELECTOR(OneController::create)},
	{kTwoScene,CONTROLLER_CREATE_SELECTOR(TwoController::create)},
	{kThreeScene,CONTROLLER_CREATE_SELECTOR(ThreeController::create)},
	{kTestScene,CONTROLLER_CREATE_SELECTOR(GameSceneBuilder::buildScene)},
	{kBuildOneScene,CONTROLLER_CREATE_SELECTOR(GameSceneBuilder::buildScene)},

};

NS_MYGAME_END

#endif //CCMVC_SCENES_SCENEREGISTERDATA_H_
