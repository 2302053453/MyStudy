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

	cocos2d::Size	winSize;
	cocos2d::Vec2	dragonPosition;
	cocos2d::TMXTiledMap*	tmap;
	cocos2d::TMXLayer*	background;
	cocos2d::TMXLayer*	metainfo;
	cocos2d::Vec2	checkPosition;
	cocos2d::Sprite*	sister;
	cocos2d::Layer* backLayer;
	cocos2d::Vec2 tileCordForPosition(cocos2d::Vec2 position);

	void createSister(cocos2d::Vec2 sisterPosition);
	//void setViewpointCenter(cocos2d::Vec2 position);
	void StartSchedule(float time);
	void setPlayerPosition(cocos2d::Vec2 position);
	
};

#endif // __HELLOWORLD_SCENE_H__
