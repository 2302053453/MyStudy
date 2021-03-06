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

	void onCapTured(Ref*);
	void afterCaptured(bool succeed, const std::string& outputFile);

	std::string _fileName;
	static const int childTag = 119;
};

#endif // __HELLOWORLD_SCENE_H__
