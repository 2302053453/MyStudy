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

	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Animations/Holygrail.plist");

	switch (currentStage)
	{
	case 1:
		createMap("TileMaps/Stage1.tmx");
		createEnemy(STAGE1_DEVIL_COUNT, STAGE1_SLIME_COUNT, STAGE1_WOLF_COUNT);
		createWeapon(STAGE1_SWORD_COUNT, STAGE1_MACE_COUNT, STAGE1_HOLY_COUNT);
		break;
	case 2:
		createMap("TileMaps/Stage2.tmx");
		createEnemy(STAGE2_DEVIL_COUNT, STAGE2_SLIME_COUNT, STAGE2_WOLF_COUNT);
		createWeapon(STAGE2_SWORD_COUNT, STAGE2_MACE_COUNT, STAGE2_HOLY_COUNT);
		break;
	case 3:
		createMap("TileMaps/Stage3.tmx");
		createEnemy(STAGE3_DEVIL_COUNT, STAGE3_SLIME_COUNT, STAGE3_WOLF_COUNT);
		createWeapon(STAGE3_SWORD_COUNT, STAGE3_MACE_COUNT, STAGE3_HOLY_COUNT);
		break;
	default:
		break;
	}
	
	createPlayer();

	auto layer = Layer::create();
	layer->setTag(30);
	layer->setColor(Color3B::GRAY);
	addChild(layer, 4);

	auto rightBackground = Sprite::create("Images/MagentaSquare.png");
	rightBackground->setPosition(RIGHT_POSITION, 100);
	rightBackground->setOpacity(100);
	layer->addChild(rightBackground);

	changeEquipImage("");
	
	auto retry = MenuItemFont::create("재시작", CC_CALLBACK_1(HelloWorld::onClick, this));
	retry->setTag(10);
	auto menu = Menu::create(retry, nullptr);
	menu->setPosition(RIGHT_POSITION, 40);
	menu->alignItemsVertically();

	layer->addChild(menu);

    return true;
}

void HelloWorld::createMap(std::string fileName)
{
	//화면 사이즈 구하기
	winSize = Director::getInstance()->getWinSize();
	map = TMXTiledMap::create(fileName);
	background = map->getLayer("Background");
	metainfo = map->getLayer("Metainfo");
	metainfo->setVisible(false);
	this->addChild(map);
}

void HelloWorld::createEnemy(int devilCount,int slimeCount, int wolfCount )
{
	auto cache = SpriteFrameCache::getInstance();
	auto enemies = map->getObjectGroup("Enemies");
	std::string objName;
	int x, y;

	for (int i = 0; i < devilCount; i++)
	{
		objName = "Devil_" + ConvertStringToInt(i+1);
		auto devilObject = enemies->getObject(objName);
		auto devil = Sprite::Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(DEVIL_IMG));
		x = devilObject["x"].asInt();
		y = devilObject["y"].asInt();

		devil->setPosition(x, y);
		devil->setName(objName);
		this->addChild(devil,2);
	}

	for (int i = 0; i < slimeCount; i++)
	{
		objName = "Slime_" + ConvertStringToInt(i + 1);
		auto slimeObject = enemies->getObject(objName);
		auto slime = Sprite::Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(SLIME_IMG));
		x = slimeObject["x"].asInt();
		y = slimeObject["y"].asInt();

		slime->setPosition(x, y);
		slime->setName(objName);
		this->addChild(slime,2);
	}

	for (int i = 0; i < wolfCount; i++)
	{
		objName = "Wolf_" + ConvertStringToInt(i + 1);
		auto wolfObject = enemies->getObject(objName);
		auto wolf = Sprite::Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(WOLF_IMG));
		x = wolfObject["x"].asInt();
		y = wolfObject["y"].asInt();

		wolf->setPosition(x, y);
		wolf->setName(objName);
		this->addChild(wolf,2);
	}

	objName = "Chest_1";
	auto treasureObject = enemies->getObject(objName);
	auto treasure = Sprite::Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(TREASURE_IMG));
	x = treasureObject["x"].asInt();
	y = treasureObject["y"].asInt();

	treasure->setPosition(x, y);
	treasure->setName(objName);
	this->addChild(treasure,2);
}	

void HelloWorld::createWeapon(int sowrdCount, int maceCount, int holyCount)
{
	auto cache = SpriteFrameCache::getInstance();
	auto weapons = map->getObjectGroup("Weapons");
	std::string objName;
	int x, y;

	for (int i = 0; i < sowrdCount; i++)
	{
		objName = "Sword_" + ConvertStringToInt(i + 1);
		auto swordObject = weapons->getObject(objName);
		auto sword = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(SWORD_IMG));
		x = swordObject["x"].asInt();
		y = swordObject["y"].asInt();
		sword->setPosition(x, y);
		sword->setName(objName);
		this->addChild(sword,1);
	}

	for (int i = 0; i < maceCount; i++)
	{
		objName = "Mace_" + ConvertStringToInt(i+1);
		auto maceObject = weapons->getObject(objName);
		auto mace = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(MACE_IMG));
		x = maceObject["x"].asInt();
		y = maceObject["y"].asInt();
		mace->setPosition(x, y);
		mace->setName(objName);
		this->addChild(mace,1);
	}

	for (int i = 0; i < holyCount; i++)
	{
		objName = "Holy_Sword_" + ConvertStringToInt(i + 1);
		auto holyObject = weapons->getObject(objName);
		auto holy = Sprite::Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(HOLY_IMG));
		x = holyObject["x"].asInt();
		y = holyObject["y"].asInt();
		holy->setPosition(x, y);
		holy->setName(objName);
		this->addChild(holy,1);
	}
	objName = "Key_1";
	auto keyObject = weapons->getObject(objName);
	auto key = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(KEY_IMG));
	x = keyObject["x"].asInt();
	y = keyObject["y"].asInt();
	key->setPosition(x, y);
	key->setName(objName);
	this->addChild(key,1);
}

std::string HelloWorld::ConvertStringToInt(int i)
{
	std::stringstream strStream;
	// 정수를 읽는다.
	strStream << i;

	// string type으로 변환
	std::string s = strStream.str();
	return s;
}

void HelloWorld::createPlayer()
{
	auto playerObj = map->getObjectGroup("Player");
	auto playerPosition = playerObj->getObject("StartPoint");
	
	player = new Player();
	int x = playerPosition["x"].asInt();
	int y = playerPosition["y"].asInt();
	player->init(Vec2(x, y));

	this->addChild(player,0);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	// 싱글터치모드로 리스너 등록
	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	Layer::onExit();
}

void HelloWorld::onClick(Ref* sender)
{
	MenuItemFont* item = (MenuItemFont*)sender;
	if (item->getTag() == 10 )
	{
		this->removeAllChildrenWithCleanup(true);
		this->init();
	}
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	Vec2 playerPos = player->getPosition();

	Vec2 diff = touchPoint - playerPos;

	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			playerPos.x += map->getTileSize().width;

			// player의 방향을 바꿔준다
			// player->setFlippedX(true);
		}
		else
		{
			playerPos.x -= map->getTileSize().width;

			// player->setFlippedX(false);
		}
	}
	else
	{
		if (diff.y>0)
			playerPos.y += map->getTileSize().height;
		else
			playerPos.y -= map->getTileSize().height;
	}

	if (playerPos.x <= (map->getMapSize().width * map->getTileSize().width) &&
		playerPos.y <= (map->getMapSize().height * map->getTileSize().height) &&
		playerPos.x >= 0 &&
		playerPos.y >= 0)

		// player의 새로운 위치지정
		this->setPlayerPosition(playerPos);

	return true;
}

void HelloWorld::removeItemAndEnemySprite(Vec2 position, bool isWeapon, std::string kind)
{
	auto cache = SpriteFrameCache::getInstance();
	auto objGroup = isWeapon ? map->getObjectGroup("Weapons") : map->getObjectGroup("Enemies");
	std::string objName;
	int count=1, x, y;

	if(isWeapon)
	{ 
		if (kind == "Sword")
			objName = "Sword_";
		else if (kind == "Mace")
			objName = "Mace_";
		else if (kind == "Holy_Sword")
			objName = "Holy_Sword_";
		else
			objName = "Key_";
	}
	else
	{
		if (kind == "Sword")
			objName = "Wolf_";
		else if (kind == "Mace")
			objName = "Slime_";
		else if (kind == "Holy_Sword")
			objName = "Devil_";
		else
			objName = "Chest_";
	}

	while (1)
	{
		auto object = objGroup->getObject(objName + ConvertStringToInt(count));
		x = object["x"].asInt();
		y = object["y"].asInt();

		auto tilePositon = tileCordForPosition(Vec2(x, y));
		if (x == 0 && y == 0)
			return;
		else if (position == tilePositon)
		{
			if(objName == "Chest_")
			{
				
				this->removeAllChildren();
				currentStage++;
				if(currentStage == 4)
				{ 
					auto scene = Clear::createScene();
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, scene));
					exit(1);
					return;
				}

				if (HelloWorld::init())
					isStageChanged = true;
			}
			else
				this->removeChildByName(objName + ConvertStringToInt(count));
			return;
			
		}
		else
			count++;
	}


}

// 현재 탭으로 선택된 타일의 위치를 가져온다.
Vec2 HelloWorld::tileCordForPosition(Vec2 position)
{
	int x = position.x / map->getTileSize().width;
	int y = ((map->getMapSize().height * map->getTileSize().height) - position.y) / map->getTileSize().height;
	return Vec2(x, y);
}

void HelloWorld::setPlayerPosition(Vec2 position)
{
	// 탭된 위치 구하기
	auto tileCord = this->tileCordForPosition(position);

	// 현재 위치의 tileGID 구하기
	int tileGid = this->metainfo->getTileGIDAt(tileCord);
	std::string weapon;
	std::string weak;
	bool isWall;

	if (tileGid)
	{
		// 타일 맵에서 GID에 해당하는 부분의 속성 읽어 오기
		auto properties = map->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			// 벽체크
			isWall = properties.asValueMap()["isWall"].asBool();
			if (isWall)
			{
				return;
			}

			// 무기 체크
			weapon = properties.asValueMap()["Weapon"].asString();
			if (weapon != "" && player->GetWeapon() == "")
			{
				// player의 무기 변경
				player->SetWeapon(weapon);

				// 타일코드 제거
				this->metainfo->removeTileAt(tileCord);

				// 무기 sprite 제거
				removeItemAndEnemySprite(tileCord, true, weapon);

				// 무기 Image 추가
				changeEquipImage(weapon);

				// player 위치 변경
				player->MovePlayer(position);
				return;
			}

			// 무기와 적 체크
			weak = properties.asValueMap()["Weak"].asString();
			if (player->hasWeapon() && player->GetWeapon() == weak)
			{
				// 사용한 무기 제거
				player->SetWeapon("");

				// 타일코드 제거
				this->metainfo->removeTileAt(tileCord);

				// 악당 sprite 제거
				removeItemAndEnemySprite(tileCord, false, weak);

				// 무기 Image 제거
				changeEquipImage("");

				// 다음 스테이지 여부 : 맞으면 다음스테이지, 아니면 플레이어 위치 변경
				if (isStageChanged) 
					isStageChanged = false;
				else 
					player->MovePlayer(position);
				return;
			}
			else
				return;
		}
	}

	player->MovePlayer(position);
}

// 우상단의 이미지를 교체한다.
void HelloWorld::changeEquipImage(std::string equip)
{
	auto cache = SpriteFrameCache::getInstance();

	// 장비Image값 초기화
	//if(equipImage != NULL)
	//	equipImage->init();
	//else
		equipImage = Sprite::create();
	
	// 알맞는 장비 Image Insert
	if(equip == "Sword")
		equipImage = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(SWORD_IMG));
	else if(equip =="Mace")
		equipImage = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(MACE_IMG));
	else if (equip == "Holy_Sword")
		equipImage = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(HOLY_IMG));
	else if (equip == "Key")
		equipImage = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(KEY_IMG));
	else // 기본이미지
	{ 
		equipImage = Sprite::create("Images/CyanSquare.png");
		equipImage->setScale(0.5f);
	}
	equipImage->setPosition(RIGHT_POSITION, 240);
	equipImage->setTag(20);

	auto layer = getChildByTag(30);
	layer->addChild(equipImage);
}