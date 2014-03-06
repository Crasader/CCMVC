#ifndef __MAINSCENE_BUILDSCENE_H__
#define __MAINSCENE_BUILDSCENE_H__

#include "BaseScene.h"

NS_MYGAME_BEGIN

class BuildScene : public BaseScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone

    void loadContents();

	// implement the "static node()" method manually
    CREATE_FUNC(BuildScene);
private:

};

NS_MYGAME_END

#endif // __MAINSCENE_BUILDSCENE_H__
