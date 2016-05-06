#pragma once
#ifndef __TESTSCENE2_H__
#define __TESTSCENE2_H__

#include "cocos2d.h"

class TestScene2 : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(TestScene2);

	void doClose(Ref* sender);
};

#endif // __TESTSCENE2_H__
