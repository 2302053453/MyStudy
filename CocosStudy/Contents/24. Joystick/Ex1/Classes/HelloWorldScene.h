#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Joystick.h"

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	Joystick* joystick;
	cocos2d::Sprite* man;

	void Tick(float t);
//	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event* evnet);

};

#endif // __HELLOWORLD_SCENE_H__
