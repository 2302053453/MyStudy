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

	Vec2 startPosition;	// �÷��̾��� ���� ��ġ

	void SetWeapon(std::string equipment);	// ���⸦ ��´�.
	std::string GetWeapon(); // ���� ������ �ִ� ���⸦ �����ش�
	bool hasWeapon();	// ���⸦ ������ �ִ��� ����
	void MovePlayer(Vec2 position); // �÷��̾ �����δ�.
private:
	std::string weapon = "";  // �÷��̾ �����ϰ� �ִ� ����
};

#endif // __PLAYER_H__
