#include "HelloWorldScene.h"

USING_NS_CC;

enum SELECT { SCISSOR=1, ROCK=2, PAPER=3, RETRY=4};

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

	// Label 생성( UserScore, computerScore, 결과문자열)
	auto myScore = Label::create("My Score : 0", "A Damn Mess", 20);
	myScore->setTag(21);
	myScore->setPosition(Vec2(100, 300));
	myScore->setColor(Color3B::BLUE);
	auto computerScore = Label::create("Computer Score : 0", "A Damn Mess", 20);
	computerScore->setTag(22);
	computerScore->setPosition(Vec2(300, 300));
	computerScore->setColor(Color3B::BLUE);

	// 처음에는 결과문자열이 없기때문에 빈값으로 초기화
	auto result = Label::create(" ", "A Damn Mess", 20);
	result->setTag(23);
	result->setPosition(Vec2(200, 270));
	result->setColor(Color3B::RED);

	auto scissor = MenuItemFont::create("[ 가위 ]", CC_CALLBACK_1(HelloWorld::OnClick,this));
	scissor->setColor(Color3B::BLACK);
	scissor->setTag(11);
	auto rock = MenuItemFont::create("[ 바위 ]", CC_CALLBACK_1(HelloWorld::OnClick, this));
	rock->setColor(Color3B::BLACK);
	rock->setTag(12);
	auto paper = MenuItemFont::create("[ 보 ]", CC_CALLBACK_1(HelloWorld::OnClick, this));
	paper->setColor(Color3B::BLACK);
	paper->setTag(13);
	auto menu = Menu::create(scissor, rock, paper, nullptr);
	menu->alignItemsHorizontally();
	menu->setPosition(240, 100);

	auto retry = MenuItemFont::create("[ 다시하기 ]", CC_CALLBACK_1(HelloWorld::OnClick, this));
	retry->setColor(Color3B::BLACK);
	retry->setTag(14);
	auto menu2 = Menu::create(retry, nullptr);
	menu2->setPosition(menu->getPositionX(), menu->getPositionY() - 50);
	
	this->addChild(menu);
	this->addChild(menu2);
	this->addChild(myScore);
	this->addChild(computerScore);
	this->addChild(result);

    return true;
}

// 가위바위보 결과 출력
int Versus(int player, int computer)
{
	// LOSE CASE( 가위(1),바위(2) / 바위(2), 보(3) / 보(3),가위(1) ) 
	if (player - computer == -1 || player - computer == 2)
		return 22;
	// WIN CASE( 가위(1), 보(3) / 바위(2), 가위(1) / 보(3), 바위(2) )
	else if (player - computer == 1 || player - computer == -2)
		return 21;
	// DRAW CASE ( 서로 같은 경우 )
	else if (player == computer)
		return 0;
}

// tag값을 받아 해당하는 sprite(그림)을 return
Sprite* ShowSelectPic(int sel)
{
	switch (sel)
	{
		case SCISSOR:
		{
			auto scissor = Sprite::create("Images/scissor.png", Rect(0, 0, 150, 150));
			return scissor;
		}
		case ROCK:
		{
			auto rock = Sprite::create("Images/rock.png", Rect(0, 0, 150, 150));
			return rock;
		}
		case PAPER:
		{
			auto paper = Sprite::create("Images/paper.png", Rect(0, 0, 150, 150));
			return paper;
		}
	}
}


void HelloWorld::OnClick(Ref* sender)
{
	static int myscore = 0;
	static int cpuscore = 0;
	int result;
	stringstream str;

	// 이름값으로 제거
	this->removeChildByName("User");
	this->removeChildByName("CPU");

	auto sel = (MenuItem*)sender;
	int userSel = sel->getTag() - 10;

	// 다시하기 : 초기화후 리턴
	if (userSel == RETRY)
	{ 
		this->removeAllChildren();
		if (init())
		{ 
			myscore = 0;
			cpuscore = 0;
			return;
		}
	}

	// 사용자가 낸 값에 따른 Sprite 정의
	Sprite* userPic= ShowSelectPic(userSel);
	userPic->setFlippedX(true);
	userPic->setPosition(Vec2(120, 200));
	userPic->setName("User");

	// 컴퓨터의 값에 따른 Sprite 정의
	int cpuSel = random(1, 3);
	Sprite* cpuPic = ShowSelectPic(cpuSel);
	cpuPic->setPosition(Vec2(300, 200));
	cpuPic->setName("CPU");
	
	// 가위바위보 결과에 따른 문자열 변경
	result = Versus(userSel, cpuSel);
	Label* lblResult = (Label*)getChildByTag(23);
	if(result != 0)
	{ 
		Label* lbl = (Label*)getChildByTag(result);
		if(result == 21)
		{ 
			str<<(++myscore);
			lbl->setString("myScore : " + str.str());
			lblResult->setString("이겼습니다!");
		}
		else if (result == 22)
		{
			str << (++cpuscore);
			lbl->setString("Computer Score : " + str.str());
			lblResult->setString("졌습니다!");
		}
	}
	else 
		lblResult->setString("비겼습니다!");

	// layer에 sprite 추가 
	this->addChild(userPic);
	this->addChild(cpuPic);
}



