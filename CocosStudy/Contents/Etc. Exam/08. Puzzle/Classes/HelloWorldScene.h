#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	 void onEnter();
	 void onExit();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void Swap(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2); // sprite1과 2간의 자리교체
	void Suffle(); // 그림들을 섞는다
	bool ChecAdjacentImage(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2); // 서로 자리교환이 가능한지 판별
	std::string ConvertIntToString(int i); // 문자를 숫자로 변환
private:
	cocos2d::Sprite* hideImage;
	cocos2d::Sprite* selectImage;
};

#endif // __HELLOWORLD_SCENE_H__
