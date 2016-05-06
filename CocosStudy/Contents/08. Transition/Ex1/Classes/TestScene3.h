#pragma once
#ifndef __TESTSCENE3_H__
#define __TESTSCENE3_H__

#include "cocos2d.h"

class TestScene3 : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(TestScene3);

	void doClose(Ref* sender);
};

#endif // __HELLOWORLD_SCENE_H__
