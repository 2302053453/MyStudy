#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

#define DEFALUT "Hero02.png"
#define BACK "Hero11.png"
#define LEFT "Hero05.png"
#define RIGHT "Hero08.png"

using namespace cocos2d;

class Player : public cocos2d::Sprite
{
public:
	Player();
	virtual Player* init(Vec2 position);

	Vec2 startPosition;	// 플레이어의 시작 위치

	void SetWeapon(std::string equipment);	// 무기를 얻는다.
	std::string GetWeapon(); // 현재 가지고 있는 무기를 보여준다
	bool hasWeapon();	// 무기를 가지고 있는지 유무
	void MovePlayer(Vec2 position); // 플레이어를 움직인다.
private:
	std::string weapon = "";  // 플레이어가 소지하고 있는 무기
};

#endif // __PLAYER_H__
