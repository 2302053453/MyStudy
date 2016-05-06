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
    
	auto batch = SpriteBatchNode::create("Animations/Player.png", 10);
	auto texture = batch->getTexture();

	// 에니메이션 디스크립터 객체를 선언하고 생성한다.
	auto animation = Animation::create();

	// 각 에니메이션 스프라이트 객체간의 시간 간격을 설정한다
	animation->setDelayPerUnit(0.03f);

	for (int i = 0; i < 9; i++)
	{
		// 첫째 줄에 19개의 프레임이 잇고, 20번째부터는 두 번째 줄에 있으므로
		// 6번째(idx=19)부터는 y좌표의 값을 증가시켜야 한다
		int column = i % 19;
		int row = i / 20;

		// texture, texture2, texture3 중 하나를 넣으면 된다
		animation->addSpriteFrameWithTexture(texture, Rect(column * 30, row * 30, 30, 30));
	}

	// 스프라이트 생성 및 초기화
	// 에니메이션 드스크립터 객체를 가지고 에니메이션 액션을 만든다
	auto man = Sprite::createWithTexture(texture, Rect(0, 0, 30, 30));

	// 에니메이션에 액션을 반복액션으로 만든다
	man->setPosition(Vec2(40, 100.0f));
	man->setScale(2.0f);
	man->setTag(2);

	// 기존 스프라이트에 에니메이션 액션을 수행한다.
	this->addChild(man);

	auto animate = Animate::create(animation);

	auto rep = RepeatForever::create(animate);
	man->runAction(rep);
	
	auto item = MenuItemFont::create("Jump!", CC_CALLBACK_1(HelloWorld::OnClick, this));
	item->setColor(Color3B::GREEN);

	auto menu = Menu::create(item, nullptr);
	menu->setPosition(Vec2(400, 60));

	this->addChild(menu);

    return true;
}

void HelloWorld::OnClick(Ref* sender)
{
	auto man = this->getChildByTag(2);
	static float preHeight = 0;
	static Sequence * seqMan;

	// 점프횟수 증가
	jumpCount++;

	// 내려오는중이거나 3단점프는 하지않는다.
	if (isJumpDown || jumpCount >MAXIMUM_JUMP_COUNT)
		return;
	else
		man->stopAction(seqMan);

	auto upSpeed1 = man->getPositionY() + HEIGHT*0.8f;
	auto upSpeed2 = man->getPositionY() + HEIGHT;

	auto downSpeed = HEIGHT + ( (man->getPositionY()- HEIGHT)*0.7f);

	// 점프 로직
	seqMan = Sequence::create(
		MoveTo::create(0.3f, Vec2(man->getPositionX(), upSpeed1)),
		MoveTo::create(0.1f, Vec2(man->getPositionX(), upSpeed2)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::SetJump,this)),
		MoveTo::create(0.3f, Vec2(man->getPositionX(), downSpeed)),
		MoveTo::create(0.1f, Vec2(man->getPositionX(), HEIGHT)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::SetJump, this)),
		nullptr);

	man->runAction(seqMan);
	
}

void HelloWorld::SetJump()
{
	// 점프유무를 변경
	isJumpDown = !isJumpDown;

	// 다 내려왔으면 점프횟수 초기화
	if (!isJumpDown)
		jumpCount = 0;
}

