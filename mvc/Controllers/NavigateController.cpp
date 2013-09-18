﻿#include "NavigateController.h"
#include "../Layer.h"

NS_CC_YHMVC_BEGIN

NavigateController::NavigateController()
:m_constrollersStack(NULL)
,m_currentController(NULL)
,m_nextController(NULL)
{
    
}

NavigateController::~NavigateController()
{
	CC_SAFE_RELEASE_NULL(m_constrollersStack);
	CC_SAFE_RELEASE_NULL(m_currentController);
	m_nextController=NULL;
}

bool NavigateController::init()
{
	if(!LayerController::init()){
		return false;
	}
	m_constrollersStack=new CCArray();
	m_constrollersStack->init();
	return true;
}

void NavigateController::pushController(LayerController* controller)
{
	m_constrollersStack->addObject(controller);
	m_nextController=controller;
	setNextController();
}

void NavigateController::popController()
{
	int size=m_constrollersStack->count();
	//退到root controller则不能在退
	if(size>1){
		m_constrollersStack->removeLastObject();
		m_nextController=static_cast<LayerController*>(m_constrollersStack->lastObject());
		setNextController();
	}
}

void NavigateController::popToRootController()
{
	int size=m_constrollersStack->count();
	if(size<=1) return;
	//退到root controller则不能在退
	while(size-->1){
		m_constrollersStack->removeLastObject();
	}
	m_nextController=static_cast<LayerController*>(m_constrollersStack->lastObject());
	setNextController();
}

void NavigateController::replaceController(LayerController *controller)
{
	int size=m_constrollersStack->count();
	m_constrollersStack->replaceObjectAtIndex(size-1,controller);
	m_nextController=controller;
	setNextController();
}

void NavigateController::setNextController()
{
	m_currentController->layerWillDisappear();
	m_nextController->layerWillAppear();

	m_pLayer->removeChild(m_currentController->getLayer());
	m_pLayer->addChild(m_nextController->getLayer());

	m_nextController->layerDidDisappear();
	m_currentController->layerDidAppear();

	m_currentController=m_nextController;
	m_currentController->retain();
	m_nextController=NULL;
}

NS_CC_YHMVC_END