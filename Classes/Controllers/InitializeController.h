#ifndef __HELLOWORLD_InitializeController_H__
#define __HELLOWORLD_InitializeController_H__

#include "yhmvc/Core/LayerController.h"
#include "yhmvc/Core/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class InitializeController:public cocos2d::yhmvc::LayerController
{
public:
	
    InitializeController(void);
    
	~InitializeController(void);

	void layerDidLoad();

	void startGameCallback(cocos2d::CCObject* pSender);
    
    CREATE_FUNC(InitializeController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_InitializeController_H__
