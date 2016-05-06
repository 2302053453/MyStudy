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

	auto map = TMXTiledMap::create("TileMaps/orthogonal-test-zorder.tmx");
	this->addChild(map, 0, 1);

	Size s = map->getContentSize();
	log("ContentSize : %f, %f", s.width, s.height);

	//map->setPosition(Vec2(-s.width / 2, 0));

	m_tamara = Sprite::create("Images/grossinis_sister1.png");
	map->addChild(m_tamara, map->getChildren().size());
	//int mapWidth = map->getMapSize().width * map->getMapSize().width;
	//m_tamara->setPosition(CC_POINT_PIXELS_TO_POINTS(Vec2(mapWidth / 2, 0)));
	m_tamara->setAnchorPoint(Vec2(0.5f, 0));

	auto move = MoveBy::create(10, Vec2(400, 320));
	auto back = move->reverse();
	auto seq = Sequence::create(move, back, nullptr);
	m_tamara->runAction(RepeatForever::create(seq));

	schedule(schedule_selector(HelloWorld::repositionSprite));

	return true;
}

void HelloWorld::repositionSprite(float time)
{
	Vec2 p = m_tamara->getPosition();
	p = CC_POINT_POINTS_TO_PIXELS(p);
	Node* map = getChildByTag(1);

	// there are only 4 layers, (grass and 3 trees layers)
	// if tamara 48, z= 4;
	// if tamara 96, z= 3;
	// if tamara 144, z= 2;

	int newZ = 4 - ((p.y -10) / 48);
	newZ = MAX(newZ, 0);

	map->reorderChild(m_tamara, newZ);
}