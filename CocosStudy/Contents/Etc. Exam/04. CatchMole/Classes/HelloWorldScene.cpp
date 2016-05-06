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
    if ( !LayerColor::initWithColor(Color4B::BLACK) )
    {
        return false;
    }
    
	// 배경 설정
	auto upperBg = Sprite::create("Images/grass_upper.png");
	upperBg->setPosition(Vec2(240, 240));
	addChild(upperBg,0);

	auto lowerBg = Sprite::create("Images/grass_lower.png");
	lowerBg->setPosition(Vec2(240, 80));
	addChild(lowerBg,2);
  
	// 두더지 추가
	Mole* mole1 = new Mole();
	mole1->setPosition(Vec2(90, 90));
	this->addChild(mole1, 1);

	Mole* mole2 = new Mole();
	mole2->setPosition(Vec2(240, 90));
	this->addChild(mole2, 1);

	Mole* mole3 = new Mole();
	mole3->setPosition(Vec2(390, 90));
	this->addChild(mole3, 1);

	mole1->doAction();
	mole2->doAction();
	mole3->doAction();


	//Texture2D *texture = TextureCache::sharedTextureCache()->addImage(mole->getMoleImagePath());
	//SpriteBatchNode* batch = SpriteBatchNode::create(mole->getMoleImagePath(), 3);
	//this->addChild(batch, 2);
	//for (int i = 0; i < 3; ++i)
	//{
	//	int positionX = 90 + (150 * i);
	//	int positionY = 150;
	//	 //Sprite* temp = Sprite::createWithTexture(texture);
	//	auto temp = new Mole();
	//	temp->setPosition(Vec2(positionX, positionY));
	//	batch->addChild(temp);
	//}

    return true;
}

