#ifndef __HELLOWORLD_TwoController_H__
#define __HELLOWORLD_TwoController_H__

#include "yhmvc/Core/LayerController.h"
#include "yhmvc/Core/Layer.h"
#include "GameMacros.h"

NS_MYGAME_BEGIN

class TwoController:public cocos2d::yhmvc::LayerController
{
public:
	
    TwoController(void);
    
	~TwoController(void);

	void layerDidLoad();

	void backCallback(cocos2d::CCObject* pSender);
    
    void nextCallback(cocos2d::CCObject* pSender);
    
    CREATE_FUNC(TwoController);
};
NS_MYGAME_END

#endif //__HELLOWORLD_TwoController_H__
