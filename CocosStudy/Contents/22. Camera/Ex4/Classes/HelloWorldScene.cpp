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
    
	sprite1 = Sprite::create("Images/grossinis_sister1.png");
	sprite1->setPosition(Vec2(240, 200));
	this->addChild(sprite1);

	sprite2 = Sprite::create("Images/grossinis_sister2.png");
	sprite2->setPosition(Vec2(240, 200));
	this->addChild(sprite2);


	sprite1->setVisible(false);
	sprite2->setVisible(true);

	// 메뉴 아이템 생성 및 초기화
	auto item = CCMenuItemFont::create(
		"Sprite Filp",
		CC_CALLBACK_1(HelloWorld::doFrontFlip, this));
	item->setColor(Color3B(0, 0, 0));

	auto menu = Menu::create(item, nullptr);

	menu->setPosition(Vec2(240, 40));
	this->addChild(menu);
    return true;
}

void HelloWorld::doFrontFlip(Ref* sender)
{
	auto firstHalf = OrbitCamera::create(
		0.5f,
		1.0f, 0,
		0, 90.0f,
		0, 0);

	if (sprite1->isVisible())
		sprite1->runAction(firstHalf);
	else
		sprite2->runAction(firstHalf);

	auto action = Sequence::create(
		DelayTime::create(0.5f),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::doBackFlip, this, this)),
		nullptr);
	this->runAction(action);
}
void HelloWorld::doBackFlip(Ref* sender)
{
	if (sprite1->isVisible())
	{
		sprite1->setVisible(false);
		sprite2->setVisible(true);
	}
	else
	{
		sprite1->setVisible(true);
		sprite2->setVisible(false);
	}

	auto secondHalf = OrbitCamera::create(
		0.5f,
		1.0f, 0,
		270, 90.0f,
		0, 0);


	if (sprite1->isVisible())
		sprite1->runAction(secondHalf);
	else
		sprite2->runAction(secondHalf);
}
