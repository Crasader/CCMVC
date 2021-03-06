#ifndef __HELLOWORLD_InitializeController_H__
#define __HELLOWORLD_InitializeController_H__

#include "mvc/LayerController.h"
#include "mvc/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN
class InitializeController:public cocos2d::yhmvc::LayerController
{
public:
	
    InitializeController(void);
    
	~InitializeController(void);

	void loadLayer();

	void startGameCallback(cocos2d::CCObject* pSender);
};
NS_MYGAME_END

#endif //__HELLOWORLD_InitializeController_H__
