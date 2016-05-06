﻿#ifndef __HELLOWORLD_SCENE_H__
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

	void OnClick1(Ref* serder);
	void OnClick2(Ref* serder);
	void OnClick3(Ref* serder);
};

#endif // __HELLOWORLD_SCENE_H__
