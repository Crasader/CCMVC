#ifndef CCMVC_SCENES_SCENEREGISTERDATA_H_
#define CCMVC_SCENES_SCENEREGISTERDATA_H_

#include <yhmvc/Core/SceneDirector.h>
#include "GameMacros.h"
//this file generate by tools.do not modify directorly

#include "Scenes/InitializeScene.h"
#include "Scenes/MainScene.h"
#include "Scenes/ShopScene.h"
#include "Scenes/OneScene.h"
#include "Scenes/TwoScene.h"
#include "Scenes/ThreeScene.h"
#include "Scenes/BuildScene.h"
#include "Scenes/AutoBuildScene.h"
#include "SceneBuilder/GameSceneBuilder.h"


NS_MYGAME_BEGIN

typedef struct SceneRegisterItem
{
    std::string name;
    cocos2d::yhmvc::SceneCreate createFun;
} SceneRegisterItem;

static SceneRegisterItem kSceneRegisterData[]=
{
	{kInitializeScene,SCENE_CREATE_SELECTOR(InitializeScene::create)},
	{kMainScene,SCENE_CREATE_SELECTOR(MainScene::create)},
	{kShopScene,SCENE_CREATE_SELECTOR(ShopScene::create)},
	{kOneScene,SCENE_CREATE_SELECTOR(OneScene::create)},
	{kTwoScene,SCENE_CREATE_SELECTOR(TwoScene::create)},
	{kThreeScene,SCENE_CREATE_SELECTOR(ThreeScene::create)},
	{kBuildScene,SCENE_CREATE_SELECTOR(BuildScene::create)},
    {kTestAScene,SCENE_CREATE_SELECTOR(GameSceneBuilder::buildScene)},

};

NS_MYGAME_END

#endif //CCMVC_SCENES_SCENEREGISTERDATA_H_
