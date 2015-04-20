//
//  Bullets.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//
#ifndef __BULLETS_OBJECT_H__
#define __BULLETS_OBJECT_H__

#include <iostream>
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;
class Bullets:public cocos2d::CCSprite{
    bool m_bDirection;
public:
    Bullets();
    ~Bullets();
    static Bullets* body();
    int m_nType;
    
    CCPoint m_nPos;
    CCSize size;
    void runMoveAction();
    void runEnemyAction();
    CCPoint randomPoint();
public:
    void setDirection(bool nDirect){m_bDirection = nDirect;}
    bool getDirection(){return m_bDirection;}
    
    CREATE_FUNC(Bullets);
    
};

#endif /*__BULLETS_OBJECT_H__*/
