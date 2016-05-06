#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "vrope-x/vrope.h";
#include "vrope-x/vstick.h";

#define PTM_RATIO 100
#define CROCDILE_CLOSE 4
#define CROCDILE_OPEN 5
#define PINEAPPLE 2

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool createBox2dWorld(bool debug);
	~HelloWorld();
	//void HelloWorld::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
	//void HelloWorld::onDraw(const Mat4 &transform, uint32_t flags);

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	
	void createRope(b2Body* bodyA, b2Vec2 anchorA, b2Body* bodyB, b2Vec2 anchorB, float sag );
	void tick(float t);
	b2Body* AddNewSprite(Vec2 point, Size size, b2BodyType bodyType, const char* spriteName, int type);
	b2Body* GetBodyAtTab(Vec2 p);
	b2Body* AddNewSpriteAt(Vec2 point);
	bool checkLineIntersection(Vec2 p1, Vec2 p2 , Vec2 p3 , Vec2 p4 );
	b2Body* createRopeTipBody();

	Size winSize;
	Texture2D* texture;
	b2World* _world;

	// For Debugging
	std::vector<VRope*>* ropes;
	std::vector<VRope*>* originRopes;
	SpriteBatchNode* ropeSpriteSheet;

protected:
	bool bDrag;
	b2MouseJoint *mouseJoint;
	b2Body *dragBody;
	b2Body *gBody;
	CustomCommand _customCmd;
	b2Body *groundBody;
	Rect crocRect;
};

#endif // __HELLOWORLD_SCENE_H__
