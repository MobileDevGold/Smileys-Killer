//
//  Bee.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#ifndef __PLATFORM_OBJECT_H__
#define __PLATFORM_OBJECT_H__

#include <iostream>
#include "cocos2d.h"
#include "GameScene.h"
#include "VisibleRect.h"
#include "Hero.h"
USING_NS_CC;

typedef enum {
    kTagHeroUp,
    kTagzHeroLeft,
    kTagHeroRight,
    kTagHeroDown,
    kTagHeroNon,
}PlatFormActionStatus;

class Game;
class PlatForm : public  CCSprite{
    
    CCPoint m_velocity;
    CCRect m_nRect;
    PlatFormActionStatus  m_nPlatFormStaus;
 
public:
    PlatForm();
    ~PlatForm();
    static PlatForm* body();
    void initWithGame(Game* game , int nIndex);
    Game* m_nGame;
    
    float radius_X();
    float radius_Y();
    float randomPos();
    
    void move(float delta);
    CCRect Rect();
    CCPoint m_nPos;
    int m_nIndex;
    
     
   
   
public:
    void setVelocity(CCPoint velocity){m_velocity = velocity;}
    CCPoint getVelocity(){return m_velocity;}
    
    void setRect(CCRect nRect){m_nRect = nRect;};
    CCRect getRect(){return m_nRect;};
    
    void setContains(PlatFormActionStatus nContains){m_nPlatFormStaus = nContains;};
    PlatFormActionStatus getContains(){ return m_nPlatFormStaus;};
    CREATE_FUNC(PlatForm);
    
    
    
};

#endif /* __PLATFORM_OBJECT_H__*/
