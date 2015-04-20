 
//  Hero.h
//  KillerSmileys
//
//  Created by TaiMing on 10/9/13.
//
//

#ifndef __HERO_OBJECT__H
#define __HERO_OBJECT__H

#include <iostream>
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;
 
typedef enum {
    kTagPlatformUp,
    kTagzPlatformLeft,
    kTagPlatformRight,
    kTagPlatformDown,
    kTagPlatformStatic,
}HeroActionStatus;
class Game;
class Hero:public CCSprite {
    HeroActionStatus m_nStatus;
public:
    Hero();
    ~Hero();
    static Hero* hero();
    void initWithGame(Game* nScene , int nLife , int nType ,CCPoint nPos , CCPoint nbarPos);
    void setLife(int nLife);
    int  getLife();
    CCRect getHeroRect();
     
    
    int m_nLife;
    int m_nType;
    
    void runJump();
    void runWalk();
     
    void runFall();
    void runStatic();
    void runFly();
    
    
    
    
    CCJumpTo* jumpAction;
    CCJumpTo* jumpAction_lifeBar;
    CCJumpTo* jumpAction_backBar;
   
    
    CCAnimate* walkAction;
    CCAnimate* staticAction;
    CCAnimate* flyAction;
    
    CCPoint m_nPos;
    CCPoint m_nbarpos;
    Game* m_nScene;
    
    CCSprite* lifeBar;
    CCSprite* backBar;
    void setStatus(HeroActionStatus nStatus){m_nStatus = nStatus;};
    HeroActionStatus getStatus(){return m_nStatus;};
    
    CREATE_FUNC(Hero);
    
};


#endif /* defined(__HERO_OBJECT_H*/

