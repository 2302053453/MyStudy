#include "HelloWorldScene.h"

USING_NS_CC;

using namespace std;

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
    
	this->myVector1();
	this->myVector2();
	this->myVector3();
    
    return true;
}


void HelloWorld::myVector1()
{
	vector<string> names;
	names.push_back("ABC");
	names.push_back("123");
	names.push_back("xyz");

	// create an iterrator that points to the first elements
	vector<string>::iterator iter = names.begin();

	// loop through, increasing to next element until the end is reached
	for (; iter != names.end(); ++iter)
	{
		log("%s", (*iter).c_str());
	}


	for (int i = 0; i < names.size(); ++i)
	{
		log("%s", names[i].c_str());
		log("%s", names.at(i).c_str());
		names.erase(names.begin() + i);
	}
	names.clear();
}
void HelloWorld::myVector2()
{
	auto img1 = Sprite::create("Images/grossini.png");
	auto img2 = Sprite::create("Images/grossinis_sister1.png");
	auto img3 = Sprite::create("Images/grossinis_sister2.png");

	img1->setTag(11);
	img2->setTag(12);
	img3->setTag(13);

	vector<Sprite*> images;

	images.push_back(img1);
	images.push_back(img2);
	images.push_back(img3);

	vector<Sprite*>::iterator iter = images.begin();

	int i = 1;
	for (; iter != images.end(); ++iter)
	{
		auto obj = (Sprite*)(*iter);
		obj->setScale(0.5f);
		obj->setPosition(Vec2(120 * i++, 240));
		this->addChild(obj);
	}

	for (iter = images.begin(); iter != images.end(); ++iter)
	{
		auto obj = (Sprite*)(*iter);
		log("Tag1.....%d", obj->getTag());
	}

	for (int i = 0; i < images.size(); ++i)
	{
		images.erase(images.begin() + i);
	}
	images.clear();
}


void HelloWorld::myVector3()
{
	auto img21 = Sprite::create("Images/grossini.png");
	auto img22 = Sprite::create("Images/grossinis_sister1.png");
	auto img23 = Sprite::create("Images/grossinis_sister2.png");

	img21->setTag(21);
	img22->setTag(22);
	img23->setTag(23);

	// STL의 vector가 아닌 cocos2d의 vector임을 주의할 것
	Vector<Sprite*> images;

	images.pushBack(img21);
	images.pushBack(img22);
	images.pushBack(img23);

	Vector<Sprite*>::iterator iter = images.begin();

	int i = 1;
	for (; iter != images.end(); ++iter)
	{
		auto obj = (Sprite*)(*iter);
		obj->setScale(0.5f);
		obj->setPosition(Vec2(120 * i++, 160));
		this->addChild(obj);
	}

	for (iter = images.begin(); iter != images.end(); ++iter)
	{
		auto obj =(Sprite*)(*iter);
		log("Tag2.....%d", obj->getTag());
	}

	for (int i = 0; i < images.size(); ++i)
	{
		auto obj = (Sprite*)images.at(i);
		images.eraseObject(obj);
	}
	images.clear();
}

