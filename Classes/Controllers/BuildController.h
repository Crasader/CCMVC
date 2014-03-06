#ifndef __HELLOWORLD_MainController_H__
#define __HELLOWORLD_MainController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN

class BuildController:public cocos2d::yhmvc::Controller
{
public:
	BuildController(void);
	~BuildController(void);
    
    void onViewEnter();
    
    void onViewExit();

    void onTestA(yhge::Event* event);
    
    yhgui::ElementEventParser* createEventParser();
    
protected:
    
	void loadViewFromFile();
};

NS_MYGAME_END

#endif //__HELLOWORLD_MainController_H__
