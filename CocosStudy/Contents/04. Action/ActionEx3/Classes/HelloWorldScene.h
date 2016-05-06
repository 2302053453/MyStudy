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

	cocos2d::Sprite* man;

	void doAction(Ref* sender);

	void ActionSequence(Ref* sender);

	void ActionSpawn(Ref* sender);

	void ActionRepeat(Ref* sender);

	void ActionDelayTime(Ref* sender);
};

#endif // __HELLOWORLD_SCENE_H__
