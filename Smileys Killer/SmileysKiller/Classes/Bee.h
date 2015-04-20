//
//  Bee.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#ifndef __BEE_OBJECT_H__
#define __BEE_OBJECT_H__

#include <iostream>
#include "cocos2d.h"
#include "GameScene.h"
#include "VisibleRect.h"
#include "Hero.h"
USING_NS_CC;
class Bee : public  CCSprite{
    
    CCPoint m_velocity;
    int m_nScore;
    CCRect m_nRect;
public:
    Bee();
    ~Bee();
    static Bee* body();
    int m_nLife;
    int accelerlator;
    CCPoint m_nPos;
    float radius_X();
    float radius_Y();
    void initWithGame(Game* game);
    
    void runFlyAction();
    int randomMove();
    void move(float delta);
    CCRect Rect();
    
    CCSprite* m_nBody;
    Game* m_nGame;
    Hero* hero;
public:
    void setVelocity(CCPoint velocity){m_velocity = velocity;}
    CCPoint getVelocity(){return m_velocity;}
    
    void setRect(CCRect nRect){m_nRect = nRect;};
    CCRect getRect(){return m_nRect;};
    
public:
    static Bee* ballWithTexture(CCTexture2D* aTexture);
    void setScore(int nScore){m_nScore = nScore;};
    int getScore(){return m_nScore;};
    
    
    CREATE_FUNC(Bee);
    
    
    
};

#endif /* __BEE_OBJECT_H__*/
