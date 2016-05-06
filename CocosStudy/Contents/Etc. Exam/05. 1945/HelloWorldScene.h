#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

#define MAX_MISSILE		2

class HelloWorld : public cocos2d::LayerColor
{
public:
	HelloWorld();
	
    static cocos2d::Scene* createScene();
	
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);
	
	bool TouchBegan(Touch *pTouch, Event *pEvent);
	void TouchMoved(Touch *pTouch, Event *pEvent);
	void TouchEnded(Touch *pTouch, Event *pEvent);
	
	void Update(float time);
	void RegenEnemy(float time);
	void Shooting(float time);
	void PutCrashEffect(const cocos2d::Vec2 &pos);
	
	void AddEnemy(const Vec2& position);
	
private:
	Sprite *player_;//주인공 플레이어

	Vector<Sprite*> *missile_[MAX_MISSILE];
	Vector<Sprite*> *enemy_;//적비행기 CCArray(배열, 리스트 구조)
	
	Point distance_;
	Size size_;
	
	float regenCheckTime_;
};

#endif // __HELLOWORLD_SCENE_H__
