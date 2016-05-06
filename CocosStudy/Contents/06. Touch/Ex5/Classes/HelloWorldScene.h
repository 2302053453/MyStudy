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

	cocos2d::EventListenerCustom* _listener1;
	cocos2d::EventListenerCustom* _listener2;
	cocos2d::LabelTTF* statusLabel;

	virtual void onEnter();
	virtual void onExit();

	void onClick1(cocos2d::Ref* sender);
	void onClick2(cocos2d::Ref* sender);
	void onEvent1(cocos2d::EventCustom* event);
	void onEvent2(cocos2d::EventCustom* event);
};

#endif // __HELLOWORLD_SCENE_H__
