#include "HelloWorldScene.h"

USING_NS_CC;
using namespace cocos2d;

// 확장 기능에 대한 namespace를 지정한다. 
using namespace cocos2d::extension;

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
    
	Size editBoxSize = Size(300, 60);
	
	// top
	m_pEditName = EditBox::create(editBoxSize, Scale9Sprite::create("extensions/orange_edit.png"));
	m_pEditName->setPosition(Vec2(240, 250));
	m_pEditName->setFontColor(Color3B::GREEN);
	m_pEditName->setPlaceHolder("Name:");
	m_pEditName->setMaxLength(8);
	m_pEditName->setReturnType(EditBox::KeyboardReturnType::DONE);
	m_pEditName->setDelegate(this);
	addChild(m_pEditName);

	// middle
	m_pEditPassword = EditBox::create(editBoxSize, Scale9Sprite::create("extensions/green_edit.png"));
	m_pEditPassword->setPosition(Vec2(240, 150));
	m_pEditPassword->setFontColor(Color3B::RED);

	// EditBox에 입력 전 입력값에 대한 힌트를 제공하는 PlaceHolder도 지정할 수 있다.
	m_pEditPassword->setPlaceHolder("Password:");

	// 입력값의 쵀대값을 지정할 수 있다
	m_pEditPassword->setMaxLength(6);

	// 비밀번호 입력 기능을 제공한다.
	m_pEditPassword->setInputFlag(EditBox::InputFlag::PASSWORD);
	m_pEditPassword->setInputMode(EditBox::InputMode::SINGLE_LINE);

	// protocolㅔㅇ 정의된 delegate 함수를 사용한다고 지정한다.
	m_pEditPassword->setDelegate(this);
	addChild(m_pEditPassword);

	// bottom
	m_pEditEmail = EditBox::create(Size(editBoxSize.width, editBoxSize.height), Scale9Sprite::create("extensions/yellow_edit.png"));
	m_pEditEmail->setPosition(Vec2(240, 50));
	m_pEditEmail->setFontColor(Color3B::GREEN);
	m_pEditEmail->setPlaceHolder("Email:");
	m_pEditEmail->setInputMode(EditBox::InputMode::EMAIL_ADDRESS);
	m_pEditEmail->setDelegate(this);
	addChild(m_pEditEmail);
    
    return true;
}

void HelloWorld::editBoxEditingDidBegin(EditBox* editBox)
{
	log("editBox %p DidBegin!", editBox);
}

void HelloWorld::editBoxEditingDidEnd(EditBox* editBox)
{
	log("editBox %p DidEnd!", editBox);
}

void HelloWorld::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
	log("editBox %p TextChanged, text: %s!", editBox, text.c_str());
}

void HelloWorld::editBoxReturn(EditBox* editBox)
{
	log("editBox %p was returned!");
}

