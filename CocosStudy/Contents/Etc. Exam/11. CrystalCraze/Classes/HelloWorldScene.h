#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GlobalDefinition.h"
#include "Game.h"

USING_NS_CC;

// 



class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


	list<struct Gem> crystals;

private:
	void PressTheButton(Ref* sender);
	void EnterGameScene();
	void ControlsCrystalAnimation(float time);

};

#endif // __HELLOWORLD_SCENE_H__
