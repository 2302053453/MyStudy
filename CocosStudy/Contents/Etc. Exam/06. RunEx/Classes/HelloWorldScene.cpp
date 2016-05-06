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
	tmap = TMXTiledMap::create("TileMaps/Run.tmx");
	background = tmap->getLayer("BackGround");
	metainfo = tmap->getLayer("MetaInfo");
	metainfo->setVisible(false);

	auto move = MoveBy::create(0.5f, Vec2(-tmap->getTileSize().width, 0));
	auto rep = RepeatForever::create(move);
	background->runAction(rep);
	this->addChild(tmap);

	// 타일맵에서 objects라고 지정한 오브젝트 레이어의 객체들 가져오기
	auto objects = tmap->getObjectGroup("Objects");

	// 오브젝트 레이어에서 SpwanPoint라고 지정한 속성값 읽어 오기
	auto spawnPoint = objects->getObject("SpwanPoint");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	Vec2 sisterPosition = Vec2(x, y);
	
	checkPosition = sisterPosition;

	createSister(sisterPosition);

	// schedule로 배경 전환 
	this->schedule(schedule_selector(HelloWorld::StartSchedule),0.5f);
	
	return true;
}

void HelloWorld::createSister(Vec2 sisterPosition)
{
	sister = Sprite::create("Images/grossinis_sister1.png");
	sister->setPosition(sisterPosition);
	sister->setScale(0.5f);
	tmap->addChild(sister);
}

void HelloWorld::StartSchedule(float time)
{
	setPlayerPosition(checkPosition);
}

// 현재 탭으로 선택된 타일의 위치를 가져온다.
Vec2 HelloWorld::tileCordForPosition(Vec2 position)
{
	int x = (position.x + abs(background->getPosition().x)) / tmap->getTileSize().width;
	int y = ((tmap->getMapSize().height * tmap->getTileSize().height) - position.y) / tmap->getTileSize().height;
	return Vec2(x, y);
}

void HelloWorld::setPlayerPosition(Vec2 position)
{
	// 추가된 부분 시작------------------------------

	// 탭된 위치 구하기
	log("%f", background->getPosition().x);

	auto tileCord = this->tileCordForPosition(position);

	// 현재 위치의 tileGID 구하기
	int tileGid = this->metainfo->getTileGIDAt(tileCord);

	if (tileGid)
	{
		// 타일 맵에서 GID에 해당하는 부분의 속성 읽어 오기

		auto properties = tmap->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			std::string Cliff = properties.asValueMap()["isCliff"].asString();
			if (Cliff == "YES")
			{
				log("Ouch!!!");
			}

			std::string Refresh = properties.asValueMap()["Refresh"].asString();
			if (Refresh == "YES")
			{
			/*	auto tmap2 = TMXTiledMap::create("TileMaps/Run.tmx");
				auto metainfo2 = tmap2->getLayer("MetaInfo");
				metainfo2->setVisible(false);
				tmap2->setPosition(960, 320);

				backLayer->addChild(tmap2, 0, 11);*/
				background->setPosition(0, 0);
				sister->setPosition(checkPosition);
				// 배경을 이어준다
			}

		}
	}

}