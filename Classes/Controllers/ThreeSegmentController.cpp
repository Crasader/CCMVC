#include "ThreeSegmentController.h"
#include "Scenes/GameSceneDirector.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

ThreeSegmentController::ThreeSegmentController(void)
:m_headerLayer(NULL)
,m_footerLayer(NULL)
,m_bodyLayer(NULL)
{
    m_sName="ThreeSegmentController";
}


ThreeSegmentController::~ThreeSegmentController(void)
{
    
}

void ThreeSegmentController::viewDidLoad()
{
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    float headerHeight=60.0f,footerHeight=64.0f;
    
    float bodyHeight=screenSize.height-headerHeight-footerHeight;
    
    //create three layer
    m_headerLayer=yhmvc::View::create();
    m_headerLayer->setContentSize(CCSizeMake(screenSize.width, headerHeight));
    m_headerLayer->setPosition(ccp(0.0f, screenSize.height-headerHeight));
    m_view->addChild(m_headerLayer);
    
    m_footerLayer=yhmvc::View::create();
    m_footerLayer->setContentSize(CCSizeMake(screenSize.width,footerHeight));
    m_view->addChild(m_footerLayer);
    
    m_bodyLayer=yhmvc::View::create();
    m_bodyLayer->setContentSize(CCSizeMake(screenSize.width, bodyHeight));
    m_bodyLayer->setPosition(ccp(0.0f, footerHeight));
    m_view->addChild(m_bodyLayer);
}

NS_MYGAME_END