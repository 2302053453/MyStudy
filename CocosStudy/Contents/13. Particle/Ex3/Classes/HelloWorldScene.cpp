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
    if ( !LayerColor::initWithColor(Color4B::BLACK) )
    {
        return false;
    }
    

    
    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPoint = touch->getLocation();
	this->showParticle(touchPoint);

	return true;
}
void HelloWorld::showParticle(Vec2 point)
{
	const char* fileName1 = "Particles/BoilingFoam.plist";
	const char* fileName2 = "Particles/BurstPipe.plist";
	const char* fileName3 = "Particles/Comet.plist";
	const char* fileName4 = "Particles/ExplodingRing.plist";
	const char* fileName5 = "Particles/Flower.plist";
	const char* fileName6 = "Particles/Galaxy.plist";
	const char* fileName7 = "Particles/LavaFlow.plist";
	const char* fileName8 = "Particles/Phoenix.plist";
	const char* fileName9 = "Particles/SmallSun.plist";
	const char* fileName10 = "Particles/SpinningPeas.plist";
	const char* fileName11 = "Particles/Spiral.plist";
	const char* fileName12 = "Particles/TestPremultiplieAlpha.plist";
	const char* fileName13 = "Particles/SpookyPeas.plist";
	const char* fileName14 = "Particles/Upsidedown.plist";

	ParticleSystem* emmiter = ParticleSystemQuad::create(fileName10);
	emmiter->setPosition(point);
	emmiter->setDuration(2.0f);
	emmiter->setAutoRemoveOnFinish(true);

	this->addChild(emmiter);
}
