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

	cocos2d::Size	winSize;
	cocos2d::Vec2	dragonPosition;
	cocos2d::Sprite*	dragon;
	cocos2d::TMXTiledMap*	tmap;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evnet);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evnet);

	void setViewpointCenter(cocos2d::Vec2 position);
};

#endif // __HELLOWORLD_SCENE_H__
