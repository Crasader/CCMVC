#include "BuildScene.h"
#include "Controllers/BuildController.h"

using namespace cocos2d;

NS_MYGAME_BEGIN

// on "init" you need to initialize your instance
void BuildScene::loadContents()
{
    BaseScene::loadContents();
    
    yhgui::NormalDocumentTreeOrganizer* treeOrganizer=new yhgui::NormalDocumentTreeOrganizer();
    treeOrganizer->init();
    treeOrganizer->registerWithTouchDispatcher();
    
    yhgui::Component* document=yhgui::Component::create();
    treeOrganizer->setDocument(document);
    
    this->addChild(document);
    
    BuildController* buildController=new BuildController();
    
    buildController->setViewFile("ui/TestScene.json");
    
    document->addChild(buildController->getView());
    
    addController(buildController);
    
    buildController->release();
}

NS_MYGAME_END