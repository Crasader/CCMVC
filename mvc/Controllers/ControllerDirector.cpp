#include "ControllerDirector.h"
#include "../Layer.h"
#include "../Window.h"

NS_CC_YHMVC_BEGIN

ControllerDirector::ControllerDirector()
:m_constrollersStack(NULL)
,m_currentController(NULL)
,m_nextController(NULL)
{
    
}

ControllerDirector::~ControllerDirector()
{
	CC_SAFE_RELEASE_NULL(m_constrollersStack);
	CC_SAFE_RELEASE_NULL(m_currentController);
	m_nextController=NULL;
}

bool ControllerDirector::init()
{
	m_constrollersStack=new CCArray();
	m_constrollersStack->init();
	return true;
}

/**
 * 开始运行一个controller.各个程序运行生命周期最多只执行一次。
 */
void ControllerDirector::runController(LayerController* controller)
{
	pushController(controller);
}

/**
 * 新的controller位于当前controller之上。
 */
void ControllerDirector::pushController(LayerController* controller)
{
	m_constrollersStack->addObject(controller);
	m_nextController=controller;
	setNextController();
}

/**
 * 替换当前的controller用新的controller显示。
 */
void ControllerDirector::replaceController(LayerController *controller)
{
	int size=m_constrollersStack->count();
	m_constrollersStack->replaceObjectAtIndex(size-1,controller);
	m_nextController=controller;
	setNextController();
}

/**
 * 结束当前controller并用栈的下一个controller做为当前显示controller。
 */
void ControllerDirector::popController()
{
	int size=m_constrollersStack->count();
	//退到root controller则不能在退
	if(size>1){
		m_constrollersStack->removeLastObject();
		m_nextController=static_cast<LayerController*>(m_constrollersStack->lastObject());
		setNextController();
	}
}

/**
 * 消除controller栈内元素，直到最后一个controller，并把其显示。
 */
void ControllerDirector::popToRootController()
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

void ControllerDirector::setNextController()
{
	if(m_currentController) m_currentController->layerWillDisappear();
	m_nextController->layerWillAppear();

	//set new root controller
	Window::getCurrentWindow()->setRootLayerController(m_nextController);

	if(m_currentController) m_currentController->layerDidDisappear();
	m_nextController->layerDidAppear();

	m_currentController=m_nextController;
	m_currentController->retain();
	m_nextController=NULL;
}

NS_CC_YHMVC_END