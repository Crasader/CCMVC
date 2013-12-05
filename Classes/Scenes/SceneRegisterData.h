//
//  SceneRegisterData.h
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#ifndef CCMVC_SceneRegisterData_h
#define CCMVC_SceneRegisterData_h

#include "mvc/Controllers/ControllerDirector.h"
#include "GameMacros.h"

typedef struct SceneRegisterItem
{
    std::string name;
    cocos2d::yhmvc::ControllerCreate createFun;
} SceneRegisterItem;

//TODO use generate tool to create this file
#include "SceneDefine.h"

#include "Controllers/InitializeController.h"
#include "Controllers/MainController.h"
#include "Controllers/ShopController.h"

NS_MYGAME_BEGIN

static SceneRegisterItem kSceneRegisterData[]=
{
    {kInitializeScene,CONTROLLER_CREATE_SELECTOR(InitializeController::create)},
    {kMainScene,CONTROLLER_CREATE_SELECTOR(MainController::create)},
    {kShopScene,CONTROLLER_CREATE_SELECTOR(ShopController::create)}
};

NS_MYGAME_END

#endif
