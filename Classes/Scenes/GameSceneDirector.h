//
//  GameSceneDirector.h
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#ifndef __CCMVC__GameSceneDirector__
#define __CCMVC__GameSceneDirector__

#include "mvc/Controllers/ControllerDirector.h"
#include "GameMacros.h"
#include "SceneDefine.h"

NS_MYGAME_BEGIN

class GameSceneDirector:public yhmvc::ControllerDirector
{
public:
    
    static GameSceneDirector* getInstance();
    
    void gotoInitScene();
    
    void gotoMainScene();
    
    void gotoShopScene();
};

NS_MYGAME_END

#endif /* defined(__CCMVC__GameSceneDirector__) */
