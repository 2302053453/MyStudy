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
    
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::changeCameraAngle, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(240, 160));
	this->addChild(sprite);

	camera = new ActionCamera;
	camera->startWithTarget(this);
    
    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	return true;
}
void HelloWorld::changeCameraAngle(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	kmVec3 eye = camera->getEye();
	eye.x = touch->getDelta().x + 0.0000000001;
	eye.y = touch->getDelta().y + 0.0000000001;
	camera->setEye(eye);
}

