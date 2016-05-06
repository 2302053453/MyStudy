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
    
	log("************************** init value **********************");

	UserDefault::getInstance()->setStringForKey("str_key", "value1");
	UserDefault::getInstance()->setIntegerForKey("int_key", 10);
	UserDefault::getInstance()->setFloatForKey("float_key", 2.3f);
	UserDefault::getInstance()->setDoubleForKey("double_key", 2.4f);
	UserDefault::getInstance()->setBoolForKey("bool_key",true);

	std::string ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());
	int i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);
	float f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);
	double d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);
	bool b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
		log("bool is true");
	else
		log("bool is false");

	log("************************** after value **********************");
	// 이 값은 종료해도 저장된다.
	UserDefault::getInstance()->setStringForKey("str_key", "value2");
	UserDefault::getInstance()->setIntegerForKey("int_key", 11);
	UserDefault::getInstance()->setFloatForKey("float_key", 3.3f);
	UserDefault::getInstance()->setDoubleForKey("double_key", 5.4f);
	UserDefault::getInstance()->setBoolForKey("bool_key", false);

	ret = UserDefault::getInstance()->getStringForKey("str_key");
	log("string is %s", ret.c_str());
	i = UserDefault::getInstance()->getIntegerForKey("int_key");
	log("integer is %d", i);
	f = UserDefault::getInstance()->getFloatForKey("float_key");
	log("float is %f", f);
	d = UserDefault::getInstance()->getDoubleForKey("double_key");
	log("double is %f", d);
	b = UserDefault::getInstance()->getBoolForKey("bool_key");
	if (b)
		log("bool is true");
	else
		log("bool is false");

    return true;
}

