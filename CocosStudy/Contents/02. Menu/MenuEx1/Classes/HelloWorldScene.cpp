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
	auto menuItem1 = MenuItemImage::create(
		"Images/btn-play-normal.png",
		"Images/btn-play-selected.png",
		CC_CALLBACK_1(HelloWorld::OnClick1, this));

	auto menuItem2 = MenuItemImage::create(
		"Images/btn-highscores-normal.png",
		"Images/btn-highscores-selected.png",
		CC_CALLBACK_1(HelloWorld::OnClick2, this));

	auto menuItem3 = MenuItemImage::create(
		"Images/btn-about-normal.png",
		"Images/btn-about-selected.png",
		CC_CALLBACK_1(HelloWorld::OnClick3, this));


	// 메뉴 생성
	// auto menu = Menu::create(menuItem1, menuItem2, menuItem3, nullptr);
	auto menu = Menu::create(menuItem1, nullptr);
    
	// 메뉴 배치
	// menu->alignItemsVertically();

	// menu의 기본 default position : 240,160
	// 이를 바꾸면 버튼위치가 변경된다.
	menu->setPosition(Vec2::ZERO);

	this->addChild(menu);

    return true;
}

void HelloWorld::OnClick1(Ref* sender)
{
	log("첫번째 메뉴가 선택되었습니다.");
}
void HelloWorld::OnClick2(Ref* sender)
{
	log("두번째 메뉴가 선택되었습니다.");
}
void HelloWorld::OnClick3(Ref* sender)
{
	log("세번째 메뉴가 선택되었습니다.");
}
