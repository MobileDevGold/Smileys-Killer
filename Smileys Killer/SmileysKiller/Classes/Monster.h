//
//  Monster.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#ifndef __MONSTER__OBJECT__H__
#define __MONSTER__OBJECT__H__

#include <iostream>
#include "cocos2d.h"
#include "GameScene.h"
#include "VisibleRect.h"

USING_NS_CC;

class Monster : public  CCSprite{
    
    CCPoint m_velocity;
    CCRect m_nRect;
    int m_nScore;
public:
    Monster();
    ~Monster();
    static Monster* body();
    int m_nLife;
    int accelerlator;
    
    float radius_X();
    float radius_Y();
    void runFlyAction();
    void randomMove();
    void move(float delta);
    CCRect Rect();
    
    CCSprite* m_nBody;
    Game* m_nGame;
public:
    void setVelocity(CCPoint velocity){m_velocity = velocity;}
    CCPoint getVelocity(){return m_velocity;}
    
    void setBounds(CCRect nRect){m_nRect = nRect;}
    CCRect getBounds(){return m_nRect;}
    
    void setScore(int nScore){m_nScore = nScore;};
    int getSCore(){return m_nScore;};

    

    CREATE_FUNC(Monster);
};

#endif /*__MONSTER__OBJECT__H__*/

 