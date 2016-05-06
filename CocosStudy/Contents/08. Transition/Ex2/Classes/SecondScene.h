#pragma once
#ifndef __SECONDSCENE_H__
#define __SECONDSCENE_H__

#include "cocos2d.h"

class SecondScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SecondScene);

	void doClose(Ref* sender);

	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onEnterTransitionDidStart();
	virtual void onExit();
	~SecondScene();
};

#endif // __HELLOWORLD_SCENE_H__
