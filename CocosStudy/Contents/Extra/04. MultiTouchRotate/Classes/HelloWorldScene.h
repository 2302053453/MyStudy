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

	virtual void onEnter();
	virtual void onExit();
	virtual void OnTouchBegan(const std::vector<cocos2d::Touch*> touches, cocos2d::Event* event);
	virtual void OnTouchMoved(const std::vector<cocos2d::Touch*> touches, cocos2d::Event* event);
	virtual void OnTouchEnded(const std::vector<cocos2d::Touch*> touches, cocos2d::Event* event);

	cocos2d::Sprite* man;
	bool select;
	float rotation;
};

#endif // __HELLOWORLD_SCENE_H__
