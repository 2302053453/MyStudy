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

	// 스프라이트
	auto cocosImage = Sprite::create("Images/powered.png");
	cocosImage->setAnchorPoint(Vec2(0, 0));

	// 배경 레이어
	// 배경 이미지의 스프라이트를 만든다. 배경 이미지의 사이즈는 640 x 480이고, 화면의 해상도는 480 x 302dlekd
	// 그러므로 모든 배경 이미지가 한 번에 보이지는 않는다.
	auto background = Sprite::create("Images/background.png");
	background->setAnchorPoint(Vec2(0, 0));

	// 레이블 : 위치구분용
	auto start = LabelTTF::create("Start", "Arial", 64);
	start->setPosition(Vec2(0, 240));
	start->setAnchorPoint(Vec2(0.0f, 0.5f));

	auto end = LabelTTF::create("End", "Arial", 64);
	end->setPosition(Vec2(640, 240));
	end->setAnchorPoint(Vec2(1.0f, 0.5f));

	auto pixel = LabelTTF::create("80 Pixel", "Arial", 24);
	pixel->setPosition(Vec2(80, 210));
	pixel->setAnchorPoint(Vec2(0.0f, 0.5f));

	// 시뮬레이터 해상도 : 480 x 640
	// 배경이미지		   640 x 480

	// 페럴렉스노드 생성
	// 아무것도 없이 비어있는 페럴렉스노드를 생성한다.
	auto voidNode = ParallaxNode::create();

	
	// 페럴렉스녹드에 배경 레이어 추가
	// 다음은 배경이미지가 페럴렉스노드와 같은 비율로 x축만 움직인다.
	voidNode->addChild(background, 1, Vec2(1.0f, 1.0f), Vec2(0, -160));
	
	// 페럴랙스노드에 배경 레이어 추가
	// 페럴렉스노드보다 2배의 비율로 x축 이동을 한다.
	// 240-(160*2) = -80
	// 4초 동안 x축 이동을 한 후의 위치는 ccp(-80,0)이 된다.
	voidNode->addChild(cocosImage, 2, Vec2(2.0f, 0.0f), Vec2(320, 0));

	// 무한반복하는 액션을 만든다.
	auto go = MoveBy::create(4, Vec2(-160, 0));
	auto goBack = go->reverse();
	auto seq = Sequence::create(go, goBack, nullptr);
	auto act = RepeatForever::create(seq);

	// 다음 줄을 remark하면 페럴렉스노드에 배치된 스프라이트 및 이미지의 초기 위치를 줄 수 있다.
	// 페럴렉스노드에 이전에 만든 액션을 적용한다.
	voidNode->runAction(act);

	// 위치 구분용 Label1,2는 background이미지와 함께 움직인다.
	// 페럴렉스노드를 layer에 추가해 화면에 보이게 한다
	background->addChild(end);
	background->addChild(start);
	

	// 위치 구분용 label은 sprite Image와 함께 움직이게 한다.
	cocosImage->addChild(pixel);

	this->addChild(voidNode);


    return true;
}

