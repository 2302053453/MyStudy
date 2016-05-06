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

	cocos2d::ActionCamera* camera;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void changeCameraAngle(cocos2d::Touch* touch, cocos2d::Event* unused_event);
};

#endif // __HELLOWORLD_SCENE_H__
