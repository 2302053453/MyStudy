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

	~HelloWorld();
	virtual void onEnter();
	void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* evnet);
	
	cocos2d::Sprite* m_pBall;
	cocos2d::Size winSize;
};

#endif // __HELLOWORLD_SCENE_H__
