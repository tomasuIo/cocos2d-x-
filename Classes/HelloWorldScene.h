#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
	
    static cocos2d::Scene* createScene();
	void menuCloseCallback1(Ref* pSender);
	void menuCloseCallback2(Ref* pSender);
    
    virtual bool init();

    
    CREATE_FUNC(HelloWorld);
};

#endif 