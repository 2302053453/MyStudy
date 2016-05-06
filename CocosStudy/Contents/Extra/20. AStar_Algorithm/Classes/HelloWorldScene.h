#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

typedef struct AStar
{
	AStar(cocos2d::Vec2 point, int gValue, int hValue, AStar* ptr)
	{
		position = point;
		adjacentValue = gValue;
		huristicValue = hValue;
		totalCost = adjacentValue + huristicValue;
		parentNode = ptr == nullptr ? this : ptr;
	}

	// adjacentValue + huristicValue
	int totalCost;
	// 연결된 node(parent)
	AStar* parentNode;
	// 현재 위치
	cocos2d::Vec2 position;
	// parent에서 현재위치로의 이동값
	int adjacentValue;
	// huristic방식으로 도착지점과의 계산값
	int huristicValue;
	
} Astar;

class HelloWorld : public cocos2d::LayerColor
{

public:
	// 연산자 오버로딩 -> openList insert시에 최소값이 위로 오도록
	struct Compare 
	{
		bool operator()(Astar* const a, Astar* const b)
		{
			return a->totalCost < b->totalCost;
		}
	};

    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	cocos2d::Size winSize;
	cocos2d::Vec2 dragonPosition;
	cocos2d::Vec2 position1;
	cocos2d::Sprite* dragon;
	cocos2d::TMXTiledMap* tmap;
	cocos2d::TMXLayer* background;
	cocos2d::TMXLayer* items;
	cocos2d::TMXLayer* metainfo;

	void createDragon();
	cocos2d::Vec2 tileCordForPosition(cocos2d::Vec2 position);
	void onEnter();
	void onExit();
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * evnet);
	void onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * evnet);
	void setPlayerPosition(cocos2d::Vec2 position);


private:

	cocos2d::Size tile;
	cocos2d::Size map;

	// tile의 대각선 값
	int tileDiagonal;

	// AStar Algorithm
	void AStarPath();

	// 도착지점
	cocos2d::Vec2 destination;

	// 도착지점 tile위치
	cocos2d::Vec2 tileDestination;

	// 도착지점에 대한 Astar Pointer
	Astar* DestinationPtr;

	// OpenList : 현재 이동할 수 있는 위치 
	std::multiset<Astar*, Compare> openList;

	// closedList : 이동한 위치
	std::multiset<Astar*, Compare> closedList;

	// closedList의 tilePosition을 저장한 list
	std::set<cocos2d::Vec2> closedTileList;

	// openList의 tilePosition을 저장한 list
	std::set<cocos2d::Vec2> openTileList;

	//  도착지점과 position과의 huristic값을 구한다
	int GetHuristicValue(cocos2d::Vec2 position);

	// 도착 지점이 같은 item이 있으면 totalcost를 비교하여 낮을쪽을 선택한다.
	void CheckSamePositionInOpenList(Astar* star);

};

#endif // __HELLOWORLD_SCENE_H__
