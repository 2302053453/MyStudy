#include "HelloWorldScene.h"
#include "SecondScene.h"
#include "SimpleAudioEngine.h" // 추가

// all platform support mp3 format. but it needs lisence cost. 

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE	"Sounds/music.mid"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE	"Sounds/background.ogg"
#else
#define MUSIC_FILE	"Sounds/background.mp3"
#endif

USING_NS_CC;
using namespace cocos2d;
using namespace CocosDenshion; // 추가

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
    
	/*
		SimpleAudioEngine과 SpriteFrameCache은 singletone객체이므로 
		다음화면에서 사용될 image와 sound파일을 미리 넣어두면
		cache메모리에 올라가고 지금 화면이 사라져도 
		해당 내용은 유지된다.
	*/

	auto item1 = MenuItemFont::create(
		"pushScene",
		CC_CALLBACK_1(HelloWorld::doChangeScene, this));
	item1->setColor(Color3B::BLACK);

	// 메뉴 생성
	auto menu = Menu::create(item1, nullptr);

	// 레이어에 메뉴 추가
	addChild(menu);
    
	// SpriteFrameCache는 여러 개의 plist를 이용해서 사용할 수 있다.
	auto cache = SpriteFrameCache::getInstance();

	// 스프라이트 시트의 위치정보 파일을 읽어들인다.]
	cache->addSpriteFramesWithFile("Animations/grossini.plist");

	// preload background and effect
	// 용량이 크면 나와야할때 로드할시에 메모리에 올라가는 속도때문에 늦게 나올 수 있다
	// 때문에 미리 메모리에 올려둔 뒤 필요할때 로드하는것이 좋다
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSIC_FILE);
	
	// set default volume
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);

	// 재생시의 delay를 줄이기 위하여 바로 시작후 중지 -> 미리 메모리에 올려서 실행까지 시킨다.
	SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE, true);
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

	log("HelloWorld :: Init");

    return true;
}

void HelloWorld::doChangeScene(Ref* sender)
{
	// 두 번째 장면
	auto scene = SecondScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::onEnter()
{
	Layer::onEnter();

	log("HelloWorld :: onEnter");
}
void HelloWorld::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();

	log("HelloWorld:: onEnterTransitionDidFinish");
}

void HelloWorld::onEnterTransitionDidStart()
{
	HelloWorld::onEnterTransitionDidStart();

	log("HelloWorld:: onEnterTransitionDidStart");
}

void HelloWorld::onExit()
{
	Layer::onExit();

	log("HelloWorld :: onExit");
}

// 다른화면을 호출한후 소멸자를 호출한다.(메모리 주의 할 것)
HelloWorld::~HelloWorld()
{
	log("HelloWorld :: dealloc");
}