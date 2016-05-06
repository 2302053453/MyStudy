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

	label = Label::create("", "Arial", 24);
	label->setPosition(300, 240);
	label->setColor(Color3B::BLACK);
	this->addChild(label);

	auto sprite = Sprite::create("Images/grossinis_sister1.png");

	pt = ProgressTimer::create(sprite);

	pt->setType(ProgressTimer::Type::RADIAL);

	pt->setPosition(Vec2(240, 160));
	this->addChild(pt);
	num = 0;
	this->schedule(schedule_selector(HelloWorld::myTick), 0.01f);
    
    return true;
}

void HelloWorld::myTick(float t)
{
	num++;
	this->SpriteProgressToRadial(num);
	if (num > 100)
		num = 0;
}

void HelloWorld::SpriteProgressToRadial(float f)
{
	pt->setPercentage(f);
}

