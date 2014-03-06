#ifndef CCMVC_GAMEMACROS_H_
#define CCMVC_GAMEMACROS_H_

#ifdef __cplusplus
#define NS_MYGAME_BEGIN                     namespace cocos2d { namespace mygame {
#define NS_MYGAME_END                       }}
#define USING_NS_MYGAME                     using namespace cocos2d::mygame
#else
#define NS_MYGAME_BEGIN
#define NS_MYGAME_END
#define USING_NS_MYGAME
#endif

#endif //CCMVC_GAMEMACROS_H_
