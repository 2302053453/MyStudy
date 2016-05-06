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
    
	Vec2 point1 = Vec2(240 - 80, 160);
	Vec2 point2 = Vec2(240 + 80, 160);
    
	auto woman1 = Sprite::create("Images/grossinis_sister1.png");
	woman1->setPosition(point1);
	this->addChild(woman1);

	auto woman2 = Sprite::create("Images/grossinis_sister2.png");
	woman2->setPosition(point2);
	this->addChild(woman2);

	Size winSize = Director::getInstance()->getWinSize();
	Vec2 center = Vec2(winSize.width / 2, winSize.height / 2);
	Vec2 diff = center - point1;

	auto act1 = ScaleBy::create(0.5f, 2.0f);
	auto act1b = act1->reverse();

	auto act2 = MoveBy::create(0.5f, diff);
	auto act2b = act2->reverse();

	auto spa1 = Spawn::create(act1, act2, nullptr);
	auto spa2 = Spawn::create(act1b, act2b, nullptr);

	auto seq = Sequence::create(spa1, spa2, nullptr);
	auto rep = RepeatForever::create(seq);

	this->runAction(rep);

    return true;
}

