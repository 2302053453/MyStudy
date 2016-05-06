#include "TestScene3.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* TestScene3::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TestScene3::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool TestScene3::init()
{
	//////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B::YELLOW))
	{
		return false;
	}
	// 메뉴 아이템 생성 및 초기화
	auto item1 = MenuItemFont::create(
		"Close Scene 3",
		CC_CALLBACK_1(TestScene3::doClose, this));
	item1->setColor(Color3B::BLACK);


	// 메뉴 생성
	auto menu = Menu::create(item1, nullptr);

	// 메뉴 위치
	menu->setPosition(Vec2(240, 50));

	this->addChild(menu);

	return true;
}

void TestScene3::doClose(Ref* sender)
{
	HelloWorld* hello;
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(hello->createTransition( 1, scene));

}

