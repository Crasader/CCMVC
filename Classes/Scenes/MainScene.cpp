﻿#include "MainScene.h"
#include "Controllers/MainController.h"
#include "Controllers/HeaderController.h"
#include "Controllers/FooterController.h"

using namespace cocos2d;

NS_MYGAME_BEGIN

// on "init" you need to initialize your instance
void MainScene::loadContents()
{
    BaseScene::loadContents();
    
	MainController* mainController=new MainController();
	mainController->init();
	this->addChild(mainController->getLayer());
    
    HeaderController* headerController=new HeaderController();
	headerController->init();
	this->addChild(headerController->getLayer());
    
    FooterController* footerController=new FooterController();
	footerController->init();
	this->addChild(footerController->getLayer());
}

NS_MYGAME_END