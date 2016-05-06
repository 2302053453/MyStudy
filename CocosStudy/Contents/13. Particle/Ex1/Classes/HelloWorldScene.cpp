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
	// 검은화면에서 보이기 떄문에 배경을 검은색으로 수정한다
    if ( !LayerColor::initWithColor(Color4B::BLACK) )
    {
        return false;
    }
    
	this->doParticles();
    
    return true;
}

void HelloWorld::doParticles()
{
	//ParticleSystem* particletest = ParticleFire::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleSun::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleFireworks::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleExplosion::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleFlower::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleGalaxy::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleMeteor::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleRain::create(); //Images/fire.png
	//ParticleSystem* particletest = ParticleSmoke::create(); //Images/fire.png
	ParticleSystem* particletest = ParticleSpiral::create(); //Images/fire.png


	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/fire.png");
	particletest->setTexture(texture);

	if (particletest != NULL)
	{
		// 파티클의 크기 조정
		particletest->setScale(1.0);

		// 파티클의 지속 시간 조정 : -1 means 'forever'
		// particles->setDuration(1.0);

		// 파티클의 위치 조정
		particletest->setPosition(Vec2(240, 160));

		this->addChild(particletest);
	}
}
