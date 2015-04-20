//
//  EnemyRobot.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#ifndef __ENEMYROBOT_OBJECT_H__
#define __ENEMYROBOT_OBJECT_H__

#include <iostream>
#include "cocos2d.h"


class EnemyRobot : public cocos2d::CCSprite{
public:
    EnemyRobot();
    ~EnemyRobot();
    static EnemyRobot* body();
    
    CREATE_FUNC(EnemyRobot);
};

#endif /*  __ENEMYROBOT_OBJECT_H__ */
