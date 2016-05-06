#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h" // 추가

// all platform support mp3 format. but it needs lisence cost. 

// android effect only support ogg
#if( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE	"Sounds/effect2.ogg"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE	"Sounds/effect2.raw"
#else
#define EFFECT_FILE	"Sounds/effect2.wav"
#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE	"Sounds/music.mid"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE	"Sounds/background.ogg"
#else
#define MUSIC_FILE	"Sounds/background.mp3"
#endif

std::string menuItems[] = {
	"play background music",
	"pause background music",
	"resume background music",
	"stop background music",
	"play effect",
	"play effect repeatly",
	"pause effect",
	"resume effect",
	"stop effect",
};

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
    
	// 메뉴 아이템 생성 및 초기화
	auto menu = CCMenu::create();

	int menuCount = sizeof(menuItems) / sizeof(menuItems[0]);
		
	for (int i = 0; i < menuCount; ++i)
	{
		auto label = LabelTTF::create(menuItems[i].c_str(), "Arial", 24);
		label->setColor(Color3B::BLACK);
		auto menuItem = MenuItemLabel::create(
			label,
			CC_CALLBACK_1(HelloWorld::doSoundAction, this));
		menu->addChild(menuItem, i + 10000);
	}

	// 메뉴 정렬
	menu->alignItemsVertically();

	this->addChild(menu);

	// preload background and effect
	// 용량이 크면 나와야할때 로드할시에 메모리에 올라가는 속도때문에 늦게 나올 수 있다
	// 때문에 미리 메모리에 올려둔 뒤 필요할때 로드하는것이 좋다
    
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSIC_FILE);
	SimpleAudioEngine::getInstance()->preloadEffect(EFFECT_FILE);

	// set default volume
	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);


    return true;
}

void HelloWorld::onExit()
{
	SimpleAudioEngine::getInstance()->unloadEffect(EFFECT_FILE);
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);

	SimpleAudioEngine::getInstance()->end();
	
	Layer::onExit();
}
void HelloWorld::doSoundAction(Ref* sender)
{
	auto menuItem = (MenuItem*)(sender);
	int idx = menuItem->getZOrder() - 10000;

	switch (idx)
	{
	case 0:// play background music
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE, true);
		break;
	case 1:// pause background music
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		break;
	case 2:// resume background music
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		break;
	case 3:// stop background music
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		break;
	case 4: // play effects
		SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
		break;
	case 5:// play effects
		SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE, true);
		break;
	case 6:// pause effects
		SimpleAudioEngine::getInstance()->pauseEffect(m_nSoundId);
		break;
	case 7:// resume effects
		SimpleAudioEngine::getInstance()->resumeEffect(m_nSoundId);
		break;
	case 8:// stop effects
		SimpleAudioEngine::getInstance()->stopEffect(m_nSoundId);
		break;
	default:
		break;
	}		
}
