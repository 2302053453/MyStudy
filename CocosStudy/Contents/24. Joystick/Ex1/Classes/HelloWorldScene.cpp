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
    
	// 조이스틱
	joystick = Joystick::create();
	this->addChild(joystick, 2);

	// sprite
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(240, 160));
	this->addChild(man);

	// touch
	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

	// schedule
	this->schedule(schedule_selector(HelloWorld::Tick));



    return true;
}

void HelloWorld::Tick(float t)
{
	float width = man->getContentSize().width / 2;
	float height = man->getContentSize().height / 2;

	float vx = man->getPosition().x + joystick->getVelocity().x * 10;
	float vy = man->getPosition().y + joystick->getVelocity().y * 10;

	if ((vx < width) || (vx>(480 - width)))
		vx = man->getPosition().x;

	if ((vy < height) || (vy>(320 - height)))
		vy = man->getPosition().y;
	man->setPosition(Vec2(vx, vy));
}




