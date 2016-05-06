#pragma once
#ifndef __CLEAR_H__
#define __CLEAR_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"

class Clear : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Clear);

	void doClose(float time);
	bool isClosed = false;
};

#endif // __TESTSCENE2_H__
