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
    
	// 메뉴 아이템 생성 및 초기화
	auto menuItem = MenuItemFont::create(
		"Action",
		CC_CALLBACK_1(HelloWorld::doAction, this));
	menuItem->setColor(Color3B::BLACK);

	// 메뉴 생성
	auto menu = Menu::create(menuItem, nullptr);

	// 메뉴 위치 지정
	menu->setPosition(Vec2(240, 160));

	this->addChild(menu);

	// sprite 추가
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 160));
	this->addChild(man);
    
    return true;
}

void HelloWorld::doAction(Ref* sender)
{
	// 기존 sprite 제거
	man->removeFromParentAndCleanup(true);

	// sprite 추가
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 160));
	this->addChild(man);

	// 다음의 함수 호출
	// this->ActionSequence(this);

	// this->ActionSpawn(this);

	// this->ActionRepeat(this);
	
	// this->ActionDelayTime(this);
}

void HelloWorld::ActionSequence(Ref* sender)
{
	auto action = Sequence::create(
		MoveBy::create(2, Vec2(400, 0)),
		RotateBy::create(2, 540),
		nullptr);

	man->runAction(action);
}

void HelloWorld::ActionSpawn(Ref* sender)
{
	/*
		4초에 4번 점프
		회전은 2초간
		2초동안 회전하면서 점프 2번, 이후에는 2초동안 그냥 점프
	*/

	auto action = Spawn::create(
		JumpBy::create(4, Vec2(400, 0), 50, 4),
		RotateBy::create(2, 720),
		nullptr);

	man->runAction(action);
}

void HelloWorld::ActionRepeat(Ref* sender)
{
	auto myActionForward = MoveBy::create(2, Vec2(400, 0));
	auto myActionBack = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBack, nullptr);

	auto rep1 = Repeat::create(myAction, 3);
	// auto rep1 = RepeatForever::create(myAction);
	man->runAction(rep1);
}

void HelloWorld::ActionDelayTime(Ref* sender)
{
	auto act1 = RotateTo::create(1, 150);
	auto act2 = RotateTo::create(1,0);
	auto myAction = Sequence::create(act1,DelayTime::create(2), act2, DelayTime::create(1), nullptr);

	auto rep1 = RepeatForever::create(myAction);
	man->runAction(rep1);
}


