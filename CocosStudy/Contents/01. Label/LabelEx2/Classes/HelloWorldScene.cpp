#include "HelloWorldScene.h"

static std::string fontList[] = {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	// info.plist에 사용자가 추가한 ttf를 정의해야 한다.
	"A Damn Mess",
	"Abberancy",
	"Abduction",
#else
	"fonts/A Damn Mess.ttf",
	"fonts/Abberancy.ttf",
	"fonts/Abduction.ttf",
#endif
};

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

	// label 생성 및 초기화 
	auto label1 = LabelTTF::create("Hello Gikimi1", "Arial", 34);
	// label 위치 지정
	label1->setPosition(240, 200);
	// label 색 지정
	label1->setColor(Color3B::BLACK);
	// layer에 label 객체 추가
	this->addChild(label1);

	/*
	ttf 파일을 프로젝트의 resources에 디렉터리로 추기
	iPhone : info.list에 리소스 추가 / 리소스에 지정된 이름으로 호출
	Android : 디렉터리를 포함한 이름으로 호출
	*/

	auto label2 = LabelTTF::create("Hello Gikimi", fontList[1].c_str(), 34);
	label2->setPosition(240, 100);
	// label 색 지정
	label2->setColor(Color3B::BLUE);
	this->addChild(label2);


	return true;
}

