//
//  HelloWorldScene.h
//  CuteAPultCocos2D-x
//
//  Created by Clawoo on 9/8/11.
//  Copyright __MyCompanyName__ 2011. All rights reserved.
//
#ifndef __HELLOWORLDSCENE_H__
#define __HELLOWORLDSCENE_H__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include<Box2D\Box2D.h>
#include "GLES-Render.h"

class HelloWorld : public cocos2d::Layer {
public:
    ~HelloWorld();
    HelloWorld();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::Scene* createScene();
    
    // adds a new sprite at a given coordinate
  //  virtual void draw();
    void tick(float t);
    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touchess, cocos2d::Event* event);
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void createBullets(int count);
    bool attachBullet();
    void resetBullet();
    void resetGame();
    
    void createTargets();
    void createTarget(const char *imageName, cocos2d::Vec2 position,  float rotation, bool isCircle, bool isStatic, bool isEnemy);

private:
    std::vector<b2Body *> m_bullets;
    std::vector<b2Body *> m_targets;
    std::vector<b2Body *> m_enemies;

    int m_currentBullet;
    b2World* m_world;
    b2Body* m_groundBody;
    b2Fixture *m_armFixture;
    b2Body *m_armBody;
    b2RevoluteJoint *m_armJoint;
    b2MouseJoint *m_mouseJoint;
    
    b2Body *m_bulletBody;
    b2WeldJoint *m_bulletJoint;
    
    
    bool m_releasingArm = false;
};

#endif // __HELLO_m_worldH__
