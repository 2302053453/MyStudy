#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void myTick(float f);
	void SpriteProgressToRadial(float f);
	
	int num;
	cocos2d::ProgressTimer *pt;
	cocos2d::Label* label;
};

#endif // __HELLOWORLD_SCENE_H__
