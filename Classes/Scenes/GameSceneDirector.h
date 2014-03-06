//
//  GameSceneDirector.h
//  CCMVC
//
//  Created by duanhouhai on 13-11-1.
//
//

#ifndef __CCMVC__GameSceneDirector__
#define __CCMVC__GameSceneDirector__

#include "yhmvc/Core/SceneDirector.h"
#include "GameMacros.h"
#include "SceneDefine.h"

NS_MYGAME_BEGIN

class GameSceneDirector:public yhmvc::SceneDirector
{
public:
    
    static GameSceneDirector* getInstance();
    
protected:
//    /**
//     * 使用注册的Scene创建函数，创建一个Scene
//     */
//    virtual yhmvc::Scene* createScene(const std::string& name);
};

NS_MYGAME_END

#endif /* defined(__CCMVC__GameSceneDirector__) */
