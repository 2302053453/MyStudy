#ifndef __SECONDSCENE_H__
#define __SECONDSCENE_H__

#include "cocos2d.h"



class SecondScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(SecondScene);

	void doSendMsg(Ref* obj);
	void doClose(Ref* obj);
};

#endif // __POPUPTOUCHEX_SECONDSCENE__
