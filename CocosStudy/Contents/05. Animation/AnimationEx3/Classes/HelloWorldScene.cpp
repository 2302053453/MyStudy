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

	/////////////////////////////////////////
	// 스프라이트시트 텍스쳐를 만들어 수동으로 파일을 구분하는 것이 아니고
	// 미리 지정한 정보파일을 이용해 파일을 구분한다.

	// 스프라이트 시트의 위치정보 파일을 읽어들인다.,
	// 같은 디렉터리 위치에 plist와 같은 이름의 png파일이 있어야 한다
	/*
		plist : xml과 비슷한 형식의 cocos에서 쓰이는 포맷 파일
		
		xml의 변천사 -> csv(comma seperage value) -> 어떠한 column의 값인지 모른다?
					 -> xml(eXtensible Markup Language ) -> 데이터가 너무 커지면 곤란, column,key와 같은 값을 줄이자
					 -> json(JavaScript Object Notation)
	*/
    
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Animations/grossini.plist");

	Vector<SpriteFrame*> animFrames;

	char str[100] = { 0 };
	for (int i = 1; i < 15; ++i)
	{
		sprintf(str, "grossini_dance_%02d.png", i);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	// 맨 첫 번째 프레임으로 주인공 스프라이트를 만든다.
	auto man = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	man->setPosition(Vec2(240, 160));
	this->addChild(man);

	// 에니메이션 만들기
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);

	man->runAction(rep);
    
    return true;
}

