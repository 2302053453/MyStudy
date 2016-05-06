#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h" 

USING_NS_CC;
using namespace CocosDenshion;

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
	
	// random method receive time seed 
	srand((int)time(NULL));

	// Insert Image

	//	background
	auto backGround = Sprite::create("CrystalCraze/Common/Image/background.png");
	backGround->setAnchorPoint(Vec2(0, 0));
	this->addChild(backGround);

	// gameLogo
	auto logo = Sprite::create("CrystalCraze/MainScene/Image/logo.png");
	logo->setPosition(160, 340);
	logo->setScale(0.01);
	logo->setTag(10);
	this->addChild(logo,3);

	// startbutton
	auto startButton = MenuItemImage::create(
		"CrystalCraze/MainScene/Image/btn-play.png",
		"CrystalCraze/MainScene/Image/btn-play-down.png",
		CC_CALLBACK_1(HelloWorld::PressTheButton, this));
	startButton->setScale(0.01f);
	startButton->setTag(21);
	startButton->setPositionY(startButton->getPositionY() - 70);
	auto menu = Menu::create(startButton, nullptr);

	this->addChild(menu,2);
	
	// sound
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::getInstance()->playBackgroundMusic(MAINBGM, true);

	// animation
	startButton->runAction(ScaleBy::create(0.5f, 30.0f));
	logo->runAction(ScaleBy::create(0.5f, 30.0f));

	// score
	std::string score = UserDefault::getInstance()->getStringForKey("score");
	if (score == "")
		score = "0";
	auto label = LabelTTF::create("High Score \n" +score, "Arial", 30,Size(300,100));
	label->setPosition(Vec2(160, 40));
	label->setColor(Color3B::WHITE);
//	label->setString(score);
	this->addChild(label,2);

	// begin schedule on crystal moving.
	this->schedule(schedule_selector(HelloWorld::ControlsCrystalAnimation, this));

    return true;
}

void HelloWorld::PressTheButton(Ref * sender)
{
	auto button = (MenuItem*)sender;
	if (button->getTag() == 21)
	{ 
		// stop background
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();

		// replace to gamescene
		auto logo = this->getChildByTag(10);
	//	auto startButton = this->getChildByTag(21);

		auto func = CallFunc::create(CC_CALLBACK_0(HelloWorld::EnterGameScene,this));

		auto seq = Sequence::create(ScaleBy::create(0.5f, 0.01f), func, nullptr);
		
		button->runAction(ScaleBy::create(0.5f, 0.01f));
		logo->runAction(seq);
	}
}

void HelloWorld::EnterGameScene()
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void HelloWorld::ControlsCrystalAnimation(float time)
{

	if (rand_0_1() < 0.02)
	{
		// gets the crystal image using on Random Number.
		auto type = random(0, 4);
		char filePath[50];
		sprintf(filePath, GEM_IMGPATH, type);
		log("%s", filePath);
		auto crystalSprite = Sprite::create(filePath);

		auto x = random() % (int)this->getContentSize().width;
	//	auto y = random() % (int)this->getContentSize().height + GEMSIZE / 2;
		auto y = 480;

		auto scale =0.5;
		auto speed = 2 * scale * GEMSIZE / 40 * (random(1,10));
		
		crystalSprite->setPosition(x, y);
		crystalSprite->setScale(scale);

		Gem gem = { type, crystalSprite, speed,false };
		crystals.push_back(gem);
		this->addChild(crystalSprite,1);
	}

	for (list<Gem>::iterator iter = crystals.begin(); iter != crystals.end();)
	{
		auto gem = iter;;
		
		Vec2 position = gem->image->getPosition();
		position.y -= gem->speed;

		gem->image->setPosition(position);

		if (position.y < -GEMSIZE / 2)
		{
			this->removeChild(gem->image, true);
			iter = crystals.erase(iter);
		}
		else
			++iter;

	}
}

