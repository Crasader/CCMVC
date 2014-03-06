
#include "BuilderExternal.h"
#include "../Controllers/MainController.h"
#include "../Controllers/FooterController.h"
#include "../Controllers/HeaderController.h"
#include "../Controllers/OneController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN

void BaseSceneControllerPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,yhgui::UIBuilder* builder)
{
    yhge::Json::Value controllersValue=properties[yhmvc::kElementPropertyController];
    if (!controllersValue.isNull()) {
        BaseScene* scene=static_cast<BaseScene*>(node);
        yhmvc::View* view=NULL;
        
        yhge::Json::Value::UInt count=controllersValue.size();
        for (int i=0;i<count;i++) {
            view=static_cast<yhmvc::View*>(builder->buildElement(controllersValue[i],node,false));
            scene->addController(view->getController());
            scene->getDocument()->addChild(view);
        }
    }
}

void BaseSceneParser::setupPropertyParser()
{
    yhgui::NodeParser::setupPropertyParser();
    
    registerPropertyParser(kElementPropertyController, BaseSceneControllerPropertyParser::create());
}


CCNode* MainControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
{
    MainController* controller=MainController::create();
    yhmvc::View* view=createView(defineData[yhgui::kPropertyNameProperties], parent, builder);
    controller->setView(view);
    
    return view;
}


CCNode* HeaderControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
{
    HeaderController* controller=HeaderController::create();
    yhmvc::View* view=createView(defineData[yhgui::kPropertyNameProperties], parent, builder);
    controller->setView(view);
    
    return view;
}


CCNode* FooterControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
{
    FooterController* controller=FooterController::create();
    yhmvc::View* view=createView(defineData[yhgui::kPropertyNameProperties], parent, builder);
    controller->setView(view);
    
    return view;
}

CCNode* OneControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
{
    OneController* controller=new OneController();
    yhmvc::View* view=createView(defineData[yhgui::kPropertyNameProperties], parent, builder);
    controller->setView(view);
    
    controller->autorelease();
    
    return view;
}

NS_MYGAME_END
