#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

// 실제 화면과 거리비율 맞추기위하여 정의
// 32pixel당 1m로 정의한다.
#define PTM_RATIO 32

USING_NS_CC;

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	~HelloWorld();

	void onEnter();
	void onExit();
	void tick(float t);
	bool onTouchBegan(Touch* touch, Event* event);
	void addNewSpriteAtPosition(Vec2 location);


private:
	Size winSize;
	Texture2D* texture;
	b2World* _world;
};

#endif // __HELLOWORLD_SCENE_H__
