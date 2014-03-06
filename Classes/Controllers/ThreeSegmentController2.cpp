#include "ThreeSegmentController2.h"
#include "Scenes/GameSceneDirector.h"
#include "HeaderController.h"
#include "FooterController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

ThreeSegmentController2::ThreeSegmentController2(void)
:m_headerLayer(NULL)
,m_footerLayer(NULL)
,m_bodyLayer(NULL)
{
    m_sName="ThreeSegmentController2";
}


ThreeSegmentController2::~ThreeSegmentController2(void)
{
    
}

void ThreeSegmentController2::viewDidLoad()
{
    CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
    
    float headerHeight=60.0f,footerHeight=64.0f;
    
    float bodyHeight=screenSize.height-headerHeight-footerHeight;
    
    //create three layer

    //create header
    HeaderController* headerController=new HeaderController();
    headerController->init();
    this->addChildController(headerController);
    headerController->release();
    headerController->setPreferredContentSize(CCSizeMake(screenSize.width, headerHeight));
    
    m_headerLayer=headerController->getView();
    m_headerLayer->setContentSize(CCSizeMake(screenSize.width, headerHeight));
    m_headerLayer->setPosition(ccp(0.0f, screenSize.height-headerHeight));
    m_view->addChild(m_headerLayer);
    
    //create footer
    FooterController* footerController=new FooterController();
    footerController->init();
    this->addChildController(footerController);
    footerController->release();
    footerController->setPreferredContentSize(CCSizeMake(screenSize.width,footerHeight));
    
    m_footerLayer=footerController->getView();
    m_footerLayer->setContentSize(CCSizeMake(screenSize.width,footerHeight));
    m_view->addChild(m_footerLayer);
    
    //create body layer
    m_bodyLayer=yhmvc::View::create();
    m_bodyLayer->setContentSize(CCSizeMake(screenSize.width, bodyHeight));
    m_bodyLayer->setPosition(ccp(0.0f, footerHeight));
    m_view->addChild(m_bodyLayer);

}

NS_MYGAME_END