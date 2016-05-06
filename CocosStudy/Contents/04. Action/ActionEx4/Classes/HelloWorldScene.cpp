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
	ball = Sprite::create("Images/Pea.png");
	ball->setPosition(Vec2(50, 100));
	ball->setScale(0.7f);
	this->addChild(ball);

	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 150));
	man->setScale(0.5f);
	this->addChild(man);

	woman1 = Sprite::create("Images/grossinis_sister1.png");
	woman1->setPosition(Vec2(50, 200));
	woman1->setScale(0.5f);
	this->addChild(woman1);

	woman2 = Sprite::create("Images/grossinis_sister2.png");
	woman2->setPosition(Vec2(50, 250));
	woman2->setScale(0.5f);
	this->addChild(woman2);

    
    return true;
}

void HelloWorld::doAction(Ref* sender)
{
	doActionReset();

	// 정상 속도
	auto move = MoveBy::create(3.0f, Vec2(400, 0));
	
	//// 빨라지기 : 시작이 늦고 나중이 빠름
	//auto ease_in = EaseIn::create(move->clone(), 4.0f);
	//// 느려지기 : 시작이 빠르고 나중이 늦음
	//auto ease_out = EaseOut::create(move->clone(), 4.0f);
	////빨라졌다 느려지기 : 시작과 끝이 빠르고 중간이 늦음
	//auto ease_inout = EaseInOut::create(move->clone(), 4.0f);

	//// 가속도가 붙은 빨라지기
	//auto ease_in = EaseExponentialIn::create(move->clone());
	//// 가속도가 붙은 느려지기
	//auto ease_out = EaseExponentialOut::create(move->clone());
	//// 가속도가 붙은 빨라졌다 느려지기
	//auto ease_inout = EaseExponentialInOut::create(move->clone());

	//// 가속도가 줄은 빨라지기
	//auto ease_in = EaseSineIn::create(move->clone());
	//// 가속도가 줄은 느려지기
	//auto ease_out = EaseSineOut::create(move->clone());
	//// 가속도가 줄은 빨라졌다 느려지기
	//auto ease_inout = EaseSineInOut::create(move->clone());

	//// 시작부분탄성
	//auto ease_in = EaseElasticIn::create(move->clone(), 0.4f);
	//// 끝부분 탄성
	//auto ease_out = EaseElasticOut::create(move->clone(), 0.4f);
	//// 처음과 끝부분 탄성
	//auto ease_inout = EaseElasticInOut::create(move->clone(), 0.4f);

	//// 시작부분 튕기기
	//auto ease_in = EaseBounceIn::create(move->clone());
	//// 끝부분 튕기기
	//auto ease_out = EaseBounceOut::create(move->clone());
	//// 시작과 끝부분 튕기기
	//auto ease_inout = EaseBounceOut::create(move->clone());

	//// 시작부분에서 범위밖으로 갔다오기
	//auto ease_in = EaseBackIn::create(move->clone());
	//// 끝부분에서 범위밖으로 갔다오기
	//auto ease_out = EaseBackOut::create(move->clone());
	//// 시작과 끝부분에서 범위밖으로 갔다오기
	//auto ease_inout = EaseBackInOut::create(move->clone());

	// 2배 가속도
	auto ease_in = Speed::create(move->clone(), 2.0f);
	// 3배 가속도
	auto ease_out = Speed::create(move->clone(), 3.0f);
	// 4배 가속도
	auto ease_inout = Speed::create(move->clone(), 4.0f);

	ball->runAction(move);
	man->runAction(ease_in);
	woman1->runAction(ease_out);
	woman2->runAction(ease_inout);
}

void HelloWorld::doActionReset()
{
	ball->setPosition(Vec2(50, 100));
	ball->setScale(0.7f);

	man->setPosition(Vec2(50, 150));
	man->setScale(0.5f);

	woman1->setPosition(Vec2(50, 200));
	woman1->setScale(0.5f);

	woman2->setPosition(Vec2(50, 250));
	woman2->setScale(0.5f);
}