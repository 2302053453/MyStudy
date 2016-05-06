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
    
	map = TMXTiledMap::create("TileMaps/untitled.tmx");


	size = map->getContentSize();

	auto bg = map->getLayer("Background");

	bg->setVisible(true);
	log("contentsize : %f, %f", size.width, size.height);
//	map->setPosition(Vec2(0, 0));
	this->addChild(map, 0, 1);
    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

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

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();
	touchPoint = map->convertToNodeSpace(touchPoint);

	Vec2 pos = touchToXY(touchPoint, 10);

	log("gid.x = %f, gid.y = %f", pos.x, pos.y);
	return true;
}

Vec2 HelloWorld::touchToXY(Vec2 touch, int mapSize)
{
	Size ts = map->getTileSize();
	int isoy = (((touch.y / ts.height) + (touch.x - (mapSize * ts.width / 2)) / ts.width) - mapSize) * -1;
	int isox = (((touch.y / ts.height) - (touch.x - (mapSize * ts.width / 2)) / ts.width) - mapSize) * -1;

	return Vec2(isox, isoy);
}