#ifndef __GAME_H__
#define __GAME_H__

#include "cocos2d.h"
#include "GlobalDefinition.h"
#include "SimpleAudioEngine.h" 


USING_NS_CC;


class GameScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	void FillGems();
	void onEnter();
	void onExit();
	void onUpdate(float t);
	void CheckTheConnect(int positionX, int positionY, int gemType);
	void RunBomb(int idx);
	void RemoveGem(int idx);
	void MoveGem(int x, int y);
	void sortGems();
	void GetHint();
	void Start();
	void EndGame();
	void playSoundEffect(int gemType);
	void CreateNewGem(int x, int y);
	virtual bool onTouchBegan(Touch* touch, Event* event);


	struct Gem crystals[80];
	std::list<Sprite*> hints;
	std::vector<int> connectedGems;
	int connectCount;
	float reduceWidthPerSecond;
	float positionXPerSecond;
	int gameTime = 0;
	int hintTime = 0;
	bool isReceivedHint = false;
	bool isTouching = false;
	int gameScore=0;
};
#endif // 
