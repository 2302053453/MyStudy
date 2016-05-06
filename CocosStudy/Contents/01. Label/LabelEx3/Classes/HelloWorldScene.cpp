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

	// 비트맵 폰트 사용법
	// 사용하려면 같은 이름의 .fnt 파일과 png파일이 필요하다.
	// 해당하는 글자는 반드시 *.fnt, *.png가 있어야 한다.
	auto label1 = LabelBMFont::create("Hello", "futura-48.fnt");
	label1->setPosition(240, 100);
	this->addChild(label1);

	// 캐릭터맵 폰트 파일 사용법
	// itemwidth와 itemheight는 같은 크기의 이미지로 된 sprite sheet를 사용해
	// spritesheet를 만들 때와 마찬가지로 글자 하나에 해당하는 크기를 나타낸다.
	// startCharMap은 첫 번째 이밎에 해당하는 ASCII 값을 말한다.
	// char 형태의 값을 사용하면 된다.

	auto label2 = LabelAtlas::create("1234", "fps_images.png", 12, 31, '.');

	label2->setPosition(240, 200);
	this->addChild(label2);


	return true;
}

