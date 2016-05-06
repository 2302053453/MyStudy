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

	MenuItemFont::setFontSize(28);

	auto menuItem = MenuItemFont::create("Action ", CC_CALLBACK_1(HelloWorld::doAction, this));

	menuItem->setColor(Color3B(0, 0, 0));

	// 메뉴 생성
	auto menu = Menu::create(menuItem, NULL);

	// 메뉴 객체
	menu->alignItemsHorizontally();
	
	// 메뉴 위치 지정
	menu->setPosition(Vec2(240, 50));
	
	// 레이어에 메뉴 객체 추가
	this->addChild(menu);
    
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(50, 200));
	this->addChild(man);

    return true;
}
void HelloWorld::doAction(Ref* sender)
{
	ccBezierConfig bzier1;
	bzier1.controlPoint_1 = Vec2(150, 150);
	bzier1.controlPoint_2 = Vec2(250, -150);
	bzier1.endPosition = Vec2(350, 0);



	// auto myAction = MoveBy::create(2, Vec2(400, 0));
	// auto myAction = JumpBy::create(2, Vec2(400, 0),50,3);
	// auto myAction = JumpTo::create(2, Vec2(400, 0), 50, 3);
	// auto myAction = BezierTo::create(3, bzier1);
	// auto myAction = BezierBy::create(3, bzier1);
	// auto myAction = Place::create(Vec2(300,200));
	// auto myAction = ScaleTo::create(2, 2.0f);
	// auto myAction = ScaleBy::create(2, 2.0f);
	// auto myAction = RotateBy::create(2, 90);
	// auto myAction = RotateTo::create(2, 90);
	// auto myAction = Blink::create(2, 5);
	// auto myAction = FadeOut::create(1.5f);
	// auto myAction = FadeIn::create(1.5f);
	// auto myAction = TintBy::create(2,128,128,128);
	// auto myAction = TintTo::create(2,0,-30,30);
	man->runAction(myAction);
}

