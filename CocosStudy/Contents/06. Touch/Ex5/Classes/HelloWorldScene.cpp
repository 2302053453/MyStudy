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
    
	statusLabel = LabelTTF::create("No custom event received", "", 20);
	statusLabel->setColor(Color3B::BLACK);
	statusLabel->setPosition(Vec2(240, 250));
	addChild(statusLabel);

	auto menuItem1 = MenuItemFont::create(
		"send Custom Event1",
		CC_CALLBACK_1(HelloWorld::onClick1, this));
	menuItem1->setColor(Color3B::BLACK);
	menuItem1->setPosition(Vec2(240, 160));

	auto menuItem2 = MenuItemFont::create(
		"send Custom Event2",
		CC_CALLBACK_1(HelloWorld::onClick2, this));
	menuItem2->setColor(Color3B::BLACK);
	menuItem2->setPosition(Vec2(240, 100));

	// 메뉴 생성
	auto menu = Menu::create(menuItem1, menuItem2, nullptr);
	menu->setPosition(Vec2(0, 0));
	addChild(menu);

    return true;
}


void HelloWorld::onEnter()
{
	Layer::onEnter();

	_listener1 = EventListenerCustom::create(
		"game_custom_event_1",
		CC_CALLBACK_1(HelloWorld::onEvent1, this));

	_eventDispatcher->addEventListenerWithFixedPriority(_listener1, 1);

	_listener2 = EventListenerCustom::create(
		"game_custom_event_2",
		CC_CALLBACK_1(HelloWorld::onEvent2, this));

	_eventDispatcher->addEventListenerWithFixedPriority(_listener2, 1);

}
void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListener(_listener1);
	_eventDispatcher->removeEventListener(_listener2);

	Layer::onExit();
}

void HelloWorld::onClick1(cocos2d::Ref* sender)
{
	static int count = 0;
	++count;
	char* buf = new char[10];
	sprintf(buf, "%d", count);

	EventCustom event("game_custom_event_1");
	event.setUserData(buf);
	_eventDispatcher->dispatchEvent(&event);
}
void HelloWorld::onClick2(cocos2d::Ref* sender)
{
	static int count = 0;
	++count;
	char* buf = new char[10];
	sprintf(buf, "%d", count);

	EventCustom event("game_custom_event_2");
	event.setUserData(buf);
	_eventDispatcher->dispatchEvent(&event);
}
void HelloWorld::onEvent1(cocos2d::EventCustom* event)
{
	std::string str("Custom event 1 received, ");
	char* buf = static_cast<char*>(event->getUserData());
	str += buf;
	str += "times";
	statusLabel->setString(str.c_str());
	delete[] buf;
}
void HelloWorld::onEvent2(cocos2d::EventCustom* event)
{
	std::string str("Custom event 2 received, ");
	char* buf = static_cast<char*>(event->getUserData());
	str += buf;
	str += "times";
	statusLabel->setString(str.c_str());
	delete[] buf;
}