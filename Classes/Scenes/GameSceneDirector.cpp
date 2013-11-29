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

NS_MYGAME_END