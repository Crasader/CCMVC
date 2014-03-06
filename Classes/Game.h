#ifndef CCMVC_GAME_H_
#define CCMVC_GAME_H_

#include "cocos2d.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN

class Game:public CCObject
{
public:
    
    
    static Game* getInstance();
    
    void setupSceneDirector();
};

NS_MYGAME_END



#endif // CCMVC_GAME_H_
