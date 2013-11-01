﻿#include "InitializeScene.h"
#include "Controllers/InitializeController.h"

USING_NS_CC;
USING_NS_CC_YHMVC;

NS_MYGAME_BEGIN
// on "init" you need to initialize your instance
void InitializeScene::loadContents()
{
    BaseScene::loadContents();
    
	InitializeController* initializeController=new InitializeController();
	this->addChild(initializeController->getLayer());
    
}

NS_MYGAME_END