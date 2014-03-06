#ifndef CCMVC_SCENEBUILDER_GAMESCENEBUILDER_H_
#define CCMVC_SCENEBUILDER_GAMESCENEBUILDER_H_

#include "cocos2d.h"
#include "GameMacros.h"
#include <yhmvc/yhmvc.h>
#include "../Scenes/BaseScene.h"

NS_MYGAME_BEGIN

class GameSceneBuilder:public yhmvc::MvcBuilder
{
public:
    
    GameSceneBuilder();
    
    ~GameSceneBuilder();
    
    static GameSceneBuilder* getInstance();
    
    /**
     * @brief 加入扩展
     * 把Scene的创建方式改为创建BaseScene
     */
    void setupExtend();
    
    static BaseScene* buildScene();
    
    static std::string getSceneDefineFile(const std::string& sceneName);
};

NS_MYGAME_END



#endif // CCMVC_SCENEBUILDER_GAMESCENEBUILDER_H_
