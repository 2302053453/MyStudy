#ifndef __MOLE_H__
#define __MOLE_H__

#include"cocos2d.h"

#define POSTION_X 90
#define POSTION_Y 90
#define INTERVAL (float)(rand() / 10 % 5)

class Mole : public cocos2d::Sprite
{
public:
	Mole();
	virtual void onEnter();
	virtual void onExit();
	virtual char* getMoleImagePath();
	virtual void doAction();
private:
	cocos2d::EventListener* _listener;
	char* filePath = "Images/mole_1.png";
};
#endif