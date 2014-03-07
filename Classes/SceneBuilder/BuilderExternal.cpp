
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

CCNode * BaseControllerCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder,CCNode* parent)
{
    return loadView(createController(), defineData, parent, builder);
}

yhmvc::View*
BaseControllerCreator::loadView(
                            BaseController* controller,
                            const yhge::Json::Value& defineData,
                            CCNode* parent,yhgui::UIBuilder* builder)
{
    //替换事件处理
    yhgui::ElementEventParser* elementEventParser=builder->getElementEventParser();
    elementEventParser->retain();
    
    builder->setElementEventParser(controller->createEventParser());
    
    yhmvc::View* view=ControllerCreator::loadView(controller, defineData, parent, builder);
    
    builder->setElementEventParser(elementEventParser);
    elementEventParser->release();
    
    return view;
}

NS_MYGAME_END
