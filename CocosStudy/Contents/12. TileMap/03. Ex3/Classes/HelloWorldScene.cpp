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
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	winSize = Director::getInstance()->getWinSize();
	// 타일 맵 읽어오기
	tmap = TMXTiledMap::create("TileMaps/test1.tmx");
	this->addChild(tmap, 0, 11);

	// 타일맵에서 objects라고 지정한 오브젝트 레이어의 객체들 가져오기
	auto objects = tmap->getObjectGroup("Objects");

	// 오브젝트 레이어에서 SpwanPoint라고 지정한 속성값 읽어 오기
	auto spawnPoint = objects->getObject("SpawnPoint");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	dragonPosition = Vec2(x, y);

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
	dragon->setPosition(dragonPosition);
	this->addChild(dragon);

	// 드래곤의 방향을 바꿔준다
	dragon->setFlippedX(true);

	// 드래곤의 사이즈를 줄여준다ㅣ. 맵에 비해 너무 크다
	dragon->setScale(0.5);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);

	return true;
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
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	Vec2 playerPos = dragon->getPosition();

	Vec2 diff = touchPoint - playerPos;

	if (diff.x > abs(diff.y))
	{
		if (diff.x > 0)
		{
			playerPos.x += tmap->getTileSize().width;

			// 드래곤의 방향을 바꿔준다
			dragon->setFlippedX(true);
		}
		else
		{
			playerPos.x -= tmap->getTileSize().width;

			dragon->setFlippedX(false);
		}
	}
	else
	{
		if(diff.y>0)
			playerPos.y += tmap->getTileSize().height;
		else
			playerPos.y -= tmap->getTileSize().height;
	}

	if (playerPos.x <= (tmap->getMapSize().width * tmap->getTileSize().width) &&
		playerPos.y <= (tmap->getMapSize().height * tmap->getTileSize().height) &&
		playerPos.x >= 0 &&
		playerPos.y >= 0)
		dragon->setPosition(playerPos);

	this->setViewpointCenter(dragon->getPosition());
}

void HelloWorld::setViewpointCenter(cocos2d::Vec2 position)
{
	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);

	x = MIN(x, (tmap->getTileSize().width * tmap->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (tmap->getTileSize().height * tmap->getTileSize().height) - winSize.height / 2);

	Vec2 actualPosition = Vec2(x, y);
	Vec2 centerView = Vec2(winSize.width / 2, winSize.height / 2);

	Vec2 viewPoint = centerView - actualPosition;

	this->setPosition(viewPoint);
}