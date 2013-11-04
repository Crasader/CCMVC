//
//  GameSceneDirector.cpp
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#include "GameSceneDirector.h"
#include "Controllers/InitializeController.h"
#include "Controllers/MainController.h"
#include "Controllers/ShopController.h"

NS_MYGAME_BEGIN

static GameSceneDirector* s_gameSceneDirectorInstance=NULL;

GameSceneDirector* GameSceneDirector::getInstance()
{
    if (!s_gameSceneDirectorInstance) {
        s_gameSceneDirectorInstance=new GameSceneDirector();
        s_gameSceneDirectorInstance->init();
    }
    
    return s_gameSceneDirectorInstance;
}

void GameSceneDirector::gotoInitScene()
{
    InitializeController* controller=new InitializeController();
    controller->init();
    
    runWithController(controller);
}

void GameSceneDirector::gotoMainScene()
{
    MainController* controller=new MainController();
    controller->init();
    
    replaceController(controller);
}

void GameSceneDirector::gotoShopScene()
{
    ShopController* controller=new ShopController();
    controller->init();
    pushController(controller);
}

NS_MYGAME_END