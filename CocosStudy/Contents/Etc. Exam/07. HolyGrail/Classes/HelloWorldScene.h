#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "StageObject.h"
#include "Player.h"
#include "Clear.h"


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

	Vector<String*> enemyList;
	Vector<String*> weaponList;

	Size winSize;	// 화면 size
	TMXTiledMap* map;		// 가져온 타일맵을 저장	
	TMXLayer* background;	// 타일맵에서의 background
	TMXLayer* enemies;	// 타일맵에서의 enemy
	TMXLayer* weapons;	// 타일맵에서의 weapon
	TMXLayer* metainfo;	// 타일맵에서의 metainfo(속성)
	Player* player = new Player();// 플레이어 객체

	
	int currentStage = 1;	// 현재 진행중인 스테이지
	void createPlayer();	// 플레이어를 생성한다
	void createMap(std::string fileName);	// 맵을 그린다.	
	void createEnemy(int devilCount, int slimeCount, int wolfCount);	// 적 개체 생성
	void createWeapon(int sowrdCount, int maceCount, int holyCount);	// 무기 생성
	void setPlayerPosition(Vec2 position); // 플레이어 위치 지정
	Vec2 tileCordForPosition(Vec2 position); // 타일 기준으로 위치를 가져온다
	void changeEquipImage(std::string equip); // 상단에 무기이미지를 교체한다

	virtual void onEnter();	// Program 진입시 실행되는 함수
	virtual void onExit();// Program 종료시 실행되는 함수
	virtual void onClick(Ref* sender); // 메뉴아이템 클릭시 발생하는 함수

	bool onTouchBegan(Touch* touch, Event* event); // touch시 event 실행함수
	void removeItemAndEnemySprite(Vec2 position, bool isWeapon, std::string kind); // Sprite의 이름과 Postion을 사용하여 Sprite를 제거한다.

	std::string ConvertStringToInt(int i); // 숫자를 문자로 변환한다

private:
	bool isStageChanged = false;	// stage 변경 유무
	Sprite* equipImage = Sprite::create();		// 장비 Image
};


#endif // __HELLOWORLD_SCENE_H__
