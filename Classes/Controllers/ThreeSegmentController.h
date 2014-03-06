#ifndef __HELLOWORLD_ThreeSegmentController_H__
#define __HELLOWORLD_ThreeSegmentController_H__

#include <yhmvc/yhmvc.h>
#include "GameMacros.h"

NS_MYGAME_BEGIN
class ThreeSegmentController:public cocos2d::yhmvc::Controller
{
public:
	
    ThreeSegmentController(void);
    
	~ThreeSegmentController(void);

	void viewDidLoad();    
    
    //get setter
    
    inline yhmvc::View* getHeaderLayer()
    {
        return m_headerLayer;
    }
    
    inline yhmvc::View* getFooterLayer()
    {
        return m_footerLayer;
    }
    
    inline yhmvc::View* getBodyLayer()
    {
        return m_bodyLayer;
    }
    
protected:
    
    yhmvc::View* m_headerLayer;
    yhmvc::View* m_footerLayer;
    yhmvc::View* m_bodyLayer;
};

NS_MYGAME_END

#endif //__HELLOWORLD_ThreeSegmentController_H__
