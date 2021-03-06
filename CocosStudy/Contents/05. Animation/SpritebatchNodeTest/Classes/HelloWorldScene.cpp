﻿#include "HelloWorldScene.h"

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
    
	Texture2D *texture = TextureCache::sharedTextureCache()->addImage("Icon.png");

	SpriteBatchNode* batch = SpriteBatchNode::createWithTexture(texture, 800);
	this->addChild(batch);
	for (int i = 0; i < 800; ++i)
	{
		int index = (i % 50) * 8;
		int rowIndex = (i / 50) * 8;
		Sprite *temp = Sprite::createWithTexture(texture);
		temp->setPosition(Vec2(index, rowIndex));
		batch->addChild(temp);
	}

    
    return true;
}

