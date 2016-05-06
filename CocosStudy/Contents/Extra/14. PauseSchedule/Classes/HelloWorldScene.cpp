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
    
	auto menuItem1 = MenuItemFont::create(
		"Pause",
		CC_CALLBACK_1(HelloWorld::doClick,this));
	menuItem1->setColor(Color3B::BLACK);

	auto menuItem2 = MenuItemFont::create(
		"Resume",
		CC_CALLBACK_1(HelloWorld::doClick, this));
	menuItem2->setColor(Color3B::BLACK);
    
	// tag 설정
	menuItem1->setTag(1);
	menuItem2->setTag(2);

	auto menu = Menu::create(menuItem1, menuItem2, nullptr);

	menu->setPosition(Vec2(240, 80));
	menu->alignItemsHorizontally();

	this->addChild(menu);

	auto man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(140, 200));
	this->addChild(man);

	auto myActionForward = MoveBy::create(2, Vec2(200, 0));
	auto myActionBack = myActionForward->reverse();
	auto myActiom = Sequence::create(myActionForward, myActionBack, nullptr);
	auto rep = RepeatForever::create(myActiom);

	man->runAction(rep);

    return true;
}

void HelloWorld::doClick(Ref* sender)
{
	auto item = (MenuItem*)sender;

	int i = item->getTag();

	// tag값에 따라 Action을 정지, 재개한다.
	if (i == 1)
		Director::getInstance()->pause();
	else
		Director::getInstance()->resume();

}

