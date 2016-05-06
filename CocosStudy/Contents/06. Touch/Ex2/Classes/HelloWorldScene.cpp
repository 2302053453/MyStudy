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
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	/////////////////////////////
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(240, 160));
	this->addChild(man);

	return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	// 멀티터치 모드로 터치 리스너 등록
	auto listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	// the priority of the touch listener is based on the draw order of sprite
	// 터치 리스너의 우선순위를 (노드가)화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ALL_AT_ONCE);

	Layer::onExit();
}

// 처음 손가락이 화면에 닿는 순간 호출된다
void HelloWorld::onTouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToWorldSpace(touchPoint);


	log("OnTouchesBegan id = %d, x = %f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);

	// touch check
	bool isTouch = man->getBoundingBox().containsPoint(touchPoint);
	if (isTouch)
		log("Sprite clicked...");

	//for (auto &item : touches)
	//{
	//	auto touch = item;
	//	auto touchPoint = touch->getLocation();

	//	log("onTouchesBegan id = %d, x=%f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);
	//}
}

// 손가락을 화면에서 떼지 않고 이리저리 움직일 때 계속해서 호출된다.
// 얼마나 자주 호출되느냐는 전적으로
// 이벤트를 핸들링하는 애플리케이션의 Run Loop에 달렸다.
void HelloWorld::onTouchMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToWorldSpace(touchPoint);

	log("onTouchesMoved id = %d, x = %f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);


	//for (auto &item : touches)
	//{
	//	auto touch = item;
	//	auto touchPoint = touch->getLocation();

	//	log("onTouchesMoved id = %d, x=%f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);
	//}
}

// 손가락을 화면에서 떼는 순간 호출된다.
void HelloWorld::onTouchEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToWorldSpace(touchPoint);

	log("onTouchEnded id = %d, x = %f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);

	//for (auto &item : touches)
	//{
	//	auto touch = item;
	//	auto touchPoint = touch->getLocation();

	//	log("onTouchesEnded id = %d, x=%f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);
	//}
}

// 시스템이 터치를 중지시키는 경우에 발생된다.(ex : 전화가 오는 경우)
void HelloWorld::onTouchCanceled(const std::vector<cocos2d::Touch*>& touches,  cocos2d::Event* event)
{
}

