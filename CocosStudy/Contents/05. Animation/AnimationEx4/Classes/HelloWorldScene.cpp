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
    
	/////////////////////////////
	
	// SpriteFrameCache는 여러 개의 plist를 이용해서 사용할 수 있다.
	auto cache = SpriteFrameCache::getInstance();
	
	// 첫 번째 스프라이트 시트의 위치정보 파일을 읽어들인다.
	// SpriteFrameCache에 addImage를 한 번에 해준다.
	cache->addSpriteFramesWithFile("Animations/grossini_family.plist");

	// 두 번째 스프라이트 시트의 위치정보 파일을 읽어들인다.]
	cache->addSpriteFramesWithFile("Animations/grossini.plist");

	// 세 번째 : 개별 스프라이트를 직접 추가한다.
	auto sprite = SpriteFrame::create("Animations/blocks9.png", Rect(0, 0, 96, 96));
	cache->addSpriteFrame(sprite, "blocks9.png");

	// form1
	auto woman = Sprite::createWithSpriteFrameName("grossinis_sister1.png");
	woman->setPosition(Vec2(120, 220));
	this->addChild(woman);
	
	// form2
	auto man = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	man->setPosition(Vec2(240, 220));
	this->addChild(man);

	// form3
	auto box = Sprite::createWithSpriteFrameName("blocks9.png");
	box->setPosition(Vec2(360, 220));
	this->addChild(box);

	// TextureCache는 하나의 텍스쳐만을 반환하므로 이전 것을 사용할 수 없다
	// 나중에 또 사용하려면 SpriteFrameCache에 createWithTexture로 저장해 둬야 한다.

	// 첫 번째 텍스쳐 로드
	auto texture = Director::getInstance()->getTextureCache()->addImage("Animations/grossini_dance_atlas.png");

	// 스프라이트 생성 및 초기화
	auto man2 = Sprite::createWithTexture(texture, Rect(0, 0, 85, 121));
	man2->setPosition(120, 100);
	this->addChild(man2);


	// 두 번째 텍스쳐 로드
	auto texture2 = Director::getInstance()->getTextureCache()->addImage("Animations/dragon_animation.png");

	// 스프라이트 생성 및 초기화
	auto dragon = Sprite::createWithTexture(texture2, Rect(0, 0, 85, 121));
	dragon->setPosition(240, 100);
	this->addChild(dragon);

	// 세 번째 텍스쳐 로드
	Director::getInstance()->getTextureCache()->addImageAsync("Animations/blocks9.png", CC_CALLBACK_1(HelloWorld::ImageLoaded, this));
    
    return true;
}

// 이미지가 메모리에 다 로딩되면 이 함수가 호출된다.
void HelloWorld::ImageLoaded(Ref* sender)
{
	auto tex = static_cast<Texture2D*>(sender);
	
	auto sprite = Sprite::createWithTexture(tex);
	sprite->setPosition(360, 100);
	this->addChild(sprite);

	log("Image Loaded %p", sender);
}

