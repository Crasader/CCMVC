#ifndef COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_
#define COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_

#include "cocos2d.h"
#include "../LayerController.h"

NS_CC_YHMVC_BEGIN

/**
 * controller切换
 * 主要用于场景级别的controller切换。即current window的root controller
 * 可能会被具体使用扩展
 */
class ControllerDirector : public CCObject
{
public:
    
    ControllerDirector();
    
    ~ControllerDirector();

	bool init();

	/**
     * 开始运行一个controller.各个程序运行生命周期最多只执行一次。
     */
    void runController(LayerController* controller);
	
	/**
     * 新的controller位于当前controller之上。
     */
    void pushController(LayerController* controller);

	/**
     * 结束当前controller并用栈的下一个controller做为当前显示controller。
     */
    void popController();

	/**
     * 替换当前的controller用新的controller显示。
     */
    void replaceController(LayerController *controller);

	/**
     * 消除controller栈内元素，直到最后一个controller，并把其显示。
     */
    void popToRootController();

	void setNextController();

	inline LayerController* getCurrentController()
	{
		return m_currentController;
	}
private:
	CCArray* m_constrollersStack;

	LayerController* m_currentController;
	LayerController* m_nextController;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_CONTROLLERS_ControllerDirector_H_
