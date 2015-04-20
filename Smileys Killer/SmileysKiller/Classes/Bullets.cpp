//
//  Bullets.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#include "Bullets.h"
#include "Global.h"
Bullets::Bullets(){
    
}

Bullets::~Bullets(){
    
}
Bullets* Bullets :: body(){
    
    Bullets* body = Bullets::create();
    return body;
}
void Bullets::runMoveAction(){
    int direction=0;
    if (m_bDirection == true) {
        direction = -1;
    }else if(m_bDirection == false){
        direction = 1;
    }
    CCMoveBy* move = CCMoveBy::create(2.0f, CCPointMake(1024*direction,0));
    this->runAction(move);
}

void Bullets::runEnemyAction(){
    
    size = CCDirector::sharedDirector()->getWinSize();
    CCJumpTo* jump = CCJumpTo::create(0.8f, randomPoint(), 50, 1);
    CCFadeTo* fade = CCFadeTo::create(1.0f, 0.0f);
    CCSequence* seq = CCSequence::create(jump,fade,NULL);
    
    this->runAction(seq);
}

CCPoint Bullets::randomPoint(){
    
    CCPoint pos;
    float pos_X =size.width / 2 + arc4random()% 150;
    float pos_Y = size.height / 2 -120;
    pos = CCPointMake(pos_X, pos_Y);
    return pos;
    
}