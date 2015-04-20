//
//  EnemyRobot.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

 
#include "EnemyRobot.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;


EnemyRobot::EnemyRobot(){
    
}
EnemyRobot::~EnemyRobot(){
    
}

EnemyRobot* EnemyRobot::body(){
    
    EnemyRobot* robot = EnemyRobot::create();
    return robot;
}