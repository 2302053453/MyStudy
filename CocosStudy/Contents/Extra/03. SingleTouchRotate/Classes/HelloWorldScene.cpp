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
    
	man = Sprite::create("Images/grossini.png");
	man->setPosition(Vec2(240, 160));
	this->addChild(man);

	select = false;

    return true;
}
void HelloWorld::onEnter()
{
	Layer::onEnter();
	// 싱글터지모드로 터치리스너 등록
	auto listener = EventListenerTouchOneByOne::create();

	// Swallow touches only available in onebyone mode
	// 핸들링도니 터치 이벤트를 터치 이벤트 array에서 지우겠다는 의미이다.
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::OnTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::OnTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::OnTouchEnded, this);

	// The priority of the touch listener is based on the draw order of sprite
	// 터치리스너의 우선순위를 (노드가) 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void HelloWorld::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Layer::onExit();
}
bool HelloWorld::OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPoint = touch->getLocation();

	select = man->getBoundingBox().containsPoint(touchPoint);

	return true;
}
void HelloWorld::OnTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (select)
	{
		Vec2 oldPoint = touch->getPreviousLocation();
		Vec2 nowPoint = touch->getLocation();

		Vec2 firstVecter = oldPoint - man->getPosition();
		float firstRotateAngle = -firstVecter.getAngle();
		float previousTouch = CC_RADIANS_TO_DEGREES(firstRotateAngle);


		Vec2 secondVecter = oldPoint - man->getPosition();
		float secondRotateAngle = -secondVecter.getAngle();
		float currentTouch = CC_RADIANS_TO_DEGREES(secondRotateAngle);

		rotation += currentTouch = previousTouch;
		rotation = fmod(rotation, 360.0f);

		man->setRotation(rotation);

	}
}
void HelloWorld::OnTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	select = false;
}
