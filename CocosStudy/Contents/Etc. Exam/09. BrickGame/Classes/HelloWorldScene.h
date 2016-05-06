#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	// Sprite용 객체 변수들
	Texture2D* texture;
	Sprite* ball;
	Sprite* paddle;
	Vector<Sprite*> targets;

	// 벽돌 숫자 조정용
	int BRICKS_HEIGHT;
	int BRICKS_WIDTH;

	// 게임이 진행중인지 체크하기 위한 변수
	bool isPlaying;
	// paddle이 터치했는지 체크하기 위한 변수
	bool isPaddleTouched;
	// 공의 움직임을 저장하기 위한 변수
	Vec2 ballMovement;

	//~HelloWorld();
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event);

	////////////////////////
	// Method List
	void initializeBricks();
	void initializeBall();
	void initializePaddle();
	void startGame(float dt);
	void gameLogic(float dt);
	void processCollision(Sprite* brick);
};

#endif // __HELLOWORLD_SCENE_H__
