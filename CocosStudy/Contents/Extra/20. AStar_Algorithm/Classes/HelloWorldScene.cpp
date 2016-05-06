#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255)) )
    {
        return false;
    }

	//화면 사이즈 구하기
	winSize = Director::getInstance()->getWinSize();
	
	// 타일 맵 읽어오기
	tmap = TMXTiledMap::create("TileMaps/AStar1.tmx");
	background = tmap->getLayer("Background");
	items = tmap->getLayer("Items");

	metainfo = tmap->getLayer("MetaInfo");
	metainfo->setVisible(false);
	this->addChild(tmap); // z-order를 -1로 하면 화면이 나오지 않는다.

	 // 타일맵에서 objects라고 지정한 오브젝트 레이어의 객체들 가져오기
	auto objects = tmap->getObjectGroup("Objects");

	// 오브젝트 레이어에서 SpwanPoint라고 지정한 속성값 읽어 오기
	auto spawnPoint = objects->getObject("SpawnPoint");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	// tile과 tileMap의 size를 구한다.
	tile = tmap->getTileSize();
	map = tmap->getMapSize();
	
	// tile의 대각선 size를 구한다.
	tileDiagonal = sqrt(tile.width*tile.width + tile.height * tile.height);

	// tilaMap을 중간으로 옶긴 조정값을 구한다.
	position1 = Vec2((winSize.width - (map.width * tile.width)) / 2,
						(winSize.height - (map.height * tile.height)) / 2);

	// 오브젝트 레이어에서 destination이라고 지정한 속성값 읽고 저장
	auto point = objects->getObject("Destination");
	destination = Vec2(point["x"].asInt()+ position1.x , point["y"].asInt()+ position1.y);

	// destination의 tile위치를 구한다.
	tileDestination = tileCordForPosition(destination);

	// 조정값에 따른 position값 변경
	dragonPosition = Vec2(x, y)+ position1;

	createDragon();

	dragon->setPosition(dragonPosition);

	tmap->setPosition(position1);

	// astar Algorithm 
	AStarPath();

	// MovePlayer();

    return true;
}

void HelloWorld::createDragon()
{
	// 움직이는 드래곤 넣기 시작
	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (int i = 0; i < 6; i++)
	{
		int idx = i % 4;
		int rowIdx = i / 4;
		animation->addSpriteFrameWithTexture(texture, Rect(idx * 130, rowIdx * 140, 130, 140));
	}

	// 스프라이트 생성 및 초기화
	dragon = Sprite::createWithTexture(texture, Rect(0, 0, 130, 140));
	this->addChild(dragon);

	// 드래곤의 방향을 바꿔준다
	dragon->setFlippedX(true);

	// 드래곤의 사이즈를 줄여준다ㅣ. 맵에 비해 너무 크다
	dragon->setScale(0.5);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);
}

// 현재 탭으로 선택된 타일의 위치를 가져온다.
Vec2 HelloWorld::tileCordForPosition(Vec2 position)
{
	int x = (position.x - position1.x) / tile.width;
	int y = ((map.height * tile.height)+ position1.y - position.y) / tile.height;

	if (x < 0 || y < 0)
	{
		log("%d, %d", x, y);
		return position;
	}

	return Vec2(x, y);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	// 싱글터치모드로 리스너 등록
	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	Layer::onExit();
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evnet)
{
	return true;
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evnet)
{
	//auto touchPoint = touch->getLocation();
	//touchPoint = this->convertToNodeSpace(touchPoint);

	//Vec2 playerPos = dragon->getPosition();

	//Vec2 diff = touchPoint - playerPos;

	//if (abs(diff.x) > abs(diff.y))
	//{
	//	if (diff.x > 0)
	//	{
	//		playerPos.x += tile.width;
	//		// 드래곤의 방향을 바꿔준다
	//		dragon->setFlippedX(true);
	//	}
	//	else
	//	{
	//		playerPos.x -= tile.width;
	//		dragon->setFlippedX(false);
	//	}
	//}
	//else
	//{
	//	if (diff.y>0)
	//		playerPos.y += tile.height;
	//	else
	//		playerPos.y -= tile.height;
	//}

	//if (playerPos.x <= (map.width * tile.width) + position1.x &&
	//	playerPos.y <= (map.height * tile.height) + position1.y &&
	//	playerPos.x >= position1.x &&
	//	playerPos.y >= position1.y)
	//	//// 드래곤의 새로운 위치지정
	//this->setPlayerPosition(playerPos);

	Vec2 position = DestinationPtr->position;
	DestinationPtr = DestinationPtr->parentNode;
	dragon->setPosition(position);
}

void HelloWorld::setPlayerPosition(Vec2 position)
{
	// 추가된 부분 시작------------------------------

	// 탭된 위치 구하기
	auto tileCord = this->tileCordForPosition(position);

	// 현재 위치의 tileGID 구하기
	int tileGid = this->metainfo->getTileGIDAt(tileCord);

	if (tileGid == 49)
		return;

	//if (tileGid)
	//{
	//	// 타일 맵에서 GID에 해당하는 부분의 속성 읽어 오기

	//	auto properties = tmap->getPropertiesForGID(tileGid);

	//	if (!properties.isNull())
	//	{
	//		std::string wall = properties.asValueMap()["Wall"].asString();
	//		if (wall == "YES")
	//		{
	//			log("Wall...");
	//			return;
	//		}

	//		// 추가된 부분 시작2----------------------------------
	//		std::string item1 = properties.asValueMap()["Items"].asString();
	//		if (item1 == "YES")
	//		{
	//			this->metainfo->removeTileAt(tileCord);
	//			items->removeTileAt(tileCord);

	//			// 먹은 수만큼 점수를 올려주는 코드가 추가적으로 필요하다.
	//			log("아이템 획득!!!  메시지가 여러 번 출력되는지 확인");
	//		}
	//	}
	//}

	// 추가된 부분 끝
	// 파라미터로 들어온 위치에 드래곤 위치 조정하기
	dragon->setPosition(position);
}

void HelloWorld::AStarPath()
{
	// 알고리즘 시작 위치 지정 (closedList에 시작값 insert)
	auto star = new Astar(dragon->getPosition(), 0, 0, nullptr);
	closedList.insert(star);

	while(1)
	{
		// closedList에 제일 마지막으로 넣은값 
		auto astar = (Astar*)(*closedList.rbegin());

		// 인접한 애들을 가져와 openList에 Insert (8방향)
		for (int x = -1; x < 2; ++x)
		{
			auto posX = astar->position.x + (x * tile.width);

			for (int y = -1; y < 2; ++y)
			{
				auto posY = astar->position.y + (y * tile.height);
				
				auto position = Vec2(posX, posY);

				// 해당위치가 tile범위를 벗어났을 경우 pass
				if (position.x > (map.width * tile.width) + position1.x ||
					position.y > (map.height * tile.height) + position1.y ||
					position.x < position1.x ||
					position.y < position1.y)
					continue;

				// 해당 위치가 장애물일 경우 pass
				auto tileCord = this->tileCordForPosition(position);
				int tileGid = this->metainfo->getTileGIDAt(tileCord);
				if (tileGid == 49)
					continue;

				// 해당위치가 closedList에 있을 경우 pass
				if(closedTileList.find(tileCord) != closedTileList.end())
					continue;

				// gValue를 구한다.
				int gValue;
				if (x != 0 && y != 0)
					gValue = tileDiagonal;
				else if (x == 0)
					gValue = tile.height;
				else if (y == 0)
					gValue = tile.width;

				// hValue를 구한다.
				int hValue = GetHuristicValue(position);

				auto star = new Astar(position, astar->adjacentValue+gValue, hValue, astar);

				if (star->totalCost == 49)
					log("%d", star->totalCost);

				// 도착지점이면 closedList에 넣은후 return 
				if (tileCord == tileDestination)
				{
					closedList.insert(star);
					DestinationPtr = star;
					return;
				}
				else
					CheckSamePositionInOpenList(star);
			}
		}

		// 현재 리스트중에서 가장 작은애를 closeList에 넣고 시작위치로 지정
		auto iter = openList.begin();
		closedTileList.insert(tileCordForPosition((*iter)->position));
		closedList.insert(*iter);
		openList.erase(iter);
	}
}

int HelloWorld::GetHuristicValue(cocos2d::Vec2 position)
{
	// 해당 position의 tile위치를 구한다.
	auto tilePosition = tileCordForPosition(position);
	
	// 도착지와의 차이값을 구한다
	auto huristic = abs(tilePosition.x - tileDestination.x);
	huristic += abs(tilePosition.y - tileDestination.y);

	return huristic;
}

void HelloWorld::CheckSamePositionInOpenList(Astar * star)
{
	// OpenList에서 위치가 같으면 비용이 높은쪽을 삭제시킨다.
	for (std::multiset<Astar*>::iterator it = openList.begin(); it != openList.end(); ++it)
	{
		if (star->position == (*it)->position)
		{
		

			// 기존값이 새로운값보다 비용이 낮을 경우 return(새로운값을 반영하지 않는다.)
			if ((*it)->totalCost <= star->totalCost)
				return;

			// 새로운값이 기존값보다 비용이 낮을 경우 기존값을 제거하고 roop를 종료한다.
			else if (star->totalCost < (*it)->totalCost)
			{
				(*it)->adjacentValue = star->adjacentValue;
				(*it)->huristicValue = star->huristicValue;
				(*it)->parentNode = star->parentNode;
				(*it)->totalCost = star->totalCost;
				(*it)->position = star->position;
				return;
			}
		}
	}

	openList.insert(star);
}






