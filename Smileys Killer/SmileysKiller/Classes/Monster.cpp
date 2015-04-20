//
//  Monster.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#include "Monster.h"

Monster::Monster(){
    
}

Monster::~Monster(){
    
}

Monster* Monster::body(){
    
    Monster* honest = Monster::create();
     
    return honest;
}
float Monster::radius_X()
{
    return getTexture()->getContentSize().width / 2;
}

float Monster::radius_Y()
{
    return getTexture()->getContentSize().height / 2;
}
CCRect Monster:: Rect(){
    
    CCRect rect = CCRectMake(getPosition().x - getContentSize().width / 2, getPosition().y - getContentSize().height / 2, getContentSize().width, getContentSize().height);
    return rect;
}

void Monster::move(float delta)
{
    
    this->setPosition( ccpAdd(getPosition(), ccpMult(m_velocity, delta)) );
    
    
    if (getPosition().x > m_nRect.origin.x +m_nRect.size.width - radius_X())
    {
        setPosition( ccp( m_nRect.origin.x +m_nRect.size.width  - radius_X(), getPosition().y) );
        m_velocity.x *= -1;
    }
    else if (getPosition().x < m_nRect.origin.x + radius_X())
    {
        setPosition( ccp(m_nRect.origin.x + radius_X(), getPosition().y) );
        m_velocity.x *= -1;
    }else if(getPosition().y > m_nRect.origin.y+m_nRect.size.height - radius_Y()){
        setPosition( ccp(getPosition().x, m_nRect.origin.y+m_nRect.size.height- radius_Y()) );
        m_velocity.y *= -1;
        
    }else if (getPosition().y < m_nRect.origin.y + radius_Y()){
        
        setPosition( ccp(getPosition().x, m_nRect.origin.y + radius_Y()) );
        m_velocity.y *= -1;
        
    }
    
    if (abs(int(m_velocity.x )) > 70) {
        m_velocity.x = arc4random()%30 + 20;
    }
    
    if (abs(int(m_velocity.y ))> 60.0f) {
        m_velocity.y = arc4random()%30 + 15;
    }
    
    accelerlator = (int) delta;
        
    
    
}
void Monster::randomMove(){
    
    CCActionInterval *rot1 = CCRotateBy::create(8, 360*2);
    CCActionInterval *rot2 = rot1->reverse();
    this->runAction(CCRepeat::create( CCSequence::create(rot1, rot2, NULL), 5 ));
 
    
}

void Monster::runFlyAction(){
    
    CCJumpBy* jump = CCJumpBy::create(0.5f, CCPointMake(20, 30), 10.0f, 4);
    this->runAction(jump);
    
}
