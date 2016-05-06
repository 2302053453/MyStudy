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
    
	// 다양한 방법으로 스프라이트시트 텍스쳐를 만든다.
	/*
		파일을 읽는부분과 렌더링하는 부분에서 많은 비용이 발생한다. 이 횟수를 줄이면
		시스템 비용이 감소하고 속도도 빨라질것이다.
	*/


	// -----------------------------------------------------------------
	// Type 1 : from Sprite
	// 모든 그름이 들어있는 큰 그림을 스프라이트로 먼저 만든다
	//auto sprite = Sprite::create("Images/grossini_dance_atlas.png");
	//auto texture = sprite->getTexture();
	// -----------------------------------------------------------------

	// -----------------------------------------------------------------
	// Type 2 : from Texture
	//auto texture = Sprite::create("Images/grossini_dance_atlas.png");
	// -----------------------------------------------------------------

	// -----------------------------------------------------------------
	// Type 3 : from BatchNode
	// small capacity, Testing resizing.
	// Don't use capacity=1 in your real game. It is expensive to resize capacity
	auto batch = SpriteBatchNode::create("Images/grossini_dance_atlas.png",10);
	auto texture = batch->getTexture();
	// -----------------------------------------------------------------


	// 에니메이션 디스크립터 객체를 선언하고 생성한다.
	auto animation = Animation::create();
	// 각 에니메이션 스프라이트 객체간의 시간 간격을 설정한다
	animation->setDelayPerUnit(0.3f);

	// 에니메이션 디스크립터 객체에 개별 스프라이트를 추가한다. 개별이즈는 85 * 121이다;
	for (int i = 0; i < 14; i++)
	{
		// 첫째 줄에 5개의 프레임이 잇고, 6번째부터는 두 번째 줄에 있으므로
		// 6번째(idx=5)부터는 y좌표의 값을 증가시켜야 한다
		int column = i % 5;
		int row = i / 5;

		// texture, texture2, texture3 중 하나를 넣으면 된다
		animation->addSpriteFrameWithTexture(texture, Rect(column * 85, row * 121, 85, 121));
	}

	// 스프라이트 생성 및 초기화
	// 에니메이션 드스크립터 객체를 가지고 에니메이션 액션을 만든다
	auto man = Sprite::createWithTexture(texture, Rect(0,0,85,121));
	// 에니메이션에 액션을 반복액션으로 만든다
	man->setPosition(Vec2(240, 160));
	// 기존 스프라이트에 에니메이션 액션을 수행한다.
	this->addChild(man);


	auto animate = Animate::create(animation);

	auto rep = RepeatForever::create(animate);
	man->runAction(rep);

    
    return true;
}



