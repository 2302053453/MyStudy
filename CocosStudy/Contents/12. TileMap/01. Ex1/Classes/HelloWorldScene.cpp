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
    
	auto tile = TMXTiledMap::create("TileMaps/test1.tmx");
	this->addChild(tile, 0, 11);
	Size s = tile->getContentSize();
	log("Content Size = %f,%f", s.width, s.height);
    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBagan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
 void HelloWorld::onExit()
 {
	 _eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);
	 Layer::onExit();
 }
 bool HelloWorld::onTouchBagan(cocos2d::Touch *touch, cocos2d::Event *evnet)
 {
	 auto touchPoint = touch->getLocation();
	 return true;
 }
 void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *evnet) 
 {
	 Vec2 diff = touch->getDelta();

	 Node* node = this->getChildByTag(11);
	 Vec2 currentPos = node->getPosition();

	 Vec2 newPos = currentPos + diff;

	 if (newPos.x < -160)
		 newPos.x = -160;
	 if (newPos.x > 0)
		 newPos.x = 0;
	 newPos.y = 0;

	 node->setPosition(newPos);
 }