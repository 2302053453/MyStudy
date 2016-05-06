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
    
	auto sp1 = Sprite::create("Images/grossini.png");
	sp1->setPosition(Vec2(120, 160));
	addChild(sp1);

	auto sp2 = Sprite::create("Images/grossinis_sister1.png");
	sp2->setPosition(Vec2(120*3, 160));
	addChild(sp2);

	auto label1 = Label::createWithTTF(TTFConfig("fonts/Marker Felt.ttf", 24), "capture all");
	label1->setColor(Color3B::BLACK);
	auto mi1 = MenuItemLabel::create(label1,
		CC_CALLBACK_1(HelloWorld::onCapTured, this));
	auto menu = Menu::create(mi1, nullptr);
	this->addChild(menu);

	menu->setPosition(240, 80);

	_fileName = "";
    
    return true;
}


void HelloWorld::onCapTured(Ref*)
{
	Director::getInstance()->getTextureCache()->removeTextureForKey(_fileName);
	removeChildByTag(childTag);
	utils::captureScreen(CC_CALLBACK_2(HelloWorld::afterCaptured, this), _fileName);
}
void HelloWorld::afterCaptured(bool succeed, const std::string& outputFile)
{
	if (succeed)
	{
		auto sp = Sprite::create(outputFile);
		addChild(sp, 0, childTag);
		sp->setPosition(240, 200);
		sp->setScale(0.25);

		_fileName = outputFile;
	}
	else
	{
		log("Capture Screen failed");
	}
}