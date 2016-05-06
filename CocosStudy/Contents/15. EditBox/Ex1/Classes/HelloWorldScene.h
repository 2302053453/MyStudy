#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

/*
	extensions/cocos-ext.h 사용하려면?
	프로젝트 우클릭 -> 속성 -> 구성속성 -> 
	C/C++ -> 일반 -> 추가 포함 디렉터리 -> 
	편집 -> $(EngineRoot) 문구 복사 -> 새로운 줄 만든 후 붙여넣기
*/
#include "cocos2d.h"

// 확장 기능을 사용하기 위해 확장 헤더를 include한다
#include "extensions/cocos-ext.h"

// EditBox를 사용하기 위한 protocol을 지정한다.
class HelloWorld : public cocos2d::LayerColor, public cocos2d::extension::EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	// EditBox 를 사용할 떄 상요하는 Delegate 함수를 선언한다.
	virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
	virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
	virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
	virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);

	// EditBox에 사용될 변수를 선언한다.
	cocos2d::extension::EditBox* m_pEditName;
	cocos2d::extension::EditBox* m_pEditPassword;
	cocos2d::extension::EditBox* m_pEditEmail;
};

#endif // __HELLOWORLD_SCENE_H__
