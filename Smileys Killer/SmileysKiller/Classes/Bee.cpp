//
//  Bee.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#include "Bee.h"
Bee::Bee(){
    
}

Bee::~Bee(){
    
}

Bee* Bee::body(){
    
    Bee* honest = Bee::create();
    
 
    return honest;
}

float Bee::radius_X()
{
    return getTexture()->getContentSize().width / 2;
}

float Bee::radius_Y()
{
    return getTexture()->getContentSize().height / 2;
}
CCRect Bee:: Rect(){
    
    CCRect rect = CCRectMake(getPosition().x - getContentSize().width / 2, getPosition().y - getContentSize().height / 2, getContentSize().width, getContentSize().height);
    return rect;
}
void Bee::initWithGame(Game *game){
    
    m_nGame = game;
}
 void Bee::move(float delta)
{
    
    m_nRect = m_nGame->m_nplayer->getHeroRect();
     this->setPosition( ccpAdd(getPosition(), ccpMult(m_velocity, delta)) );
    
     
    
    
    if (getPosition().x > VisibleRect::right().x - radius_X())
    {
        setPosition( ccp( VisibleRect::right().x - radius_X(), getPosition().y) );
        m_velocity.x *= -1.0f;
    }
    else if (getPosition().x < VisibleRect::left().x + radius_X())
    {
        setPosition( ccp(VisibleRect::left().x + radius_X(), getPosition().y) );
        m_velocity.x *= -1.0f;
    }else if(getPosition().y > VisibleRect::top().y - radius_Y()){
        setPosition( ccp(getPosition().x, VisibleRect::top().y - radius_Y()) );
        m_velocity.y *= -1.0f;
        
    }else if (getPosition().y < VisibleRect::bottom().y + radius_Y()){
        
        setPosition( ccp(getPosition().x, VisibleRect::bottom().y + radius_Y()) );
        m_velocity.y *= -1.0f;
        
    }else if(getPosition().x < m_nRect.origin.x+ m_nRect.size.width + radius_X() && getPosition().y < m_nRect.origin.y+ m_nRect.size.height &&  getPosition().y> m_nRect.origin.y)
    {
        setPosition( ccp( m_nRect.origin.x+ m_nRect.size.width + radius_X(), getPosition().y) );
        m_velocity.x *= -2.0f;
        m_nGame->CheckHeroLife(CCPointZero);
         
    }
//    else if (getPosition().x > m_nRect.origin.x-radius_X() && getPosition().y > m_nRect.origin.y && getPosition().y< m_nRect.origin.y+ m_nRect.size.height)
//    {
//        setPosition( ccp(m_nRect.origin.x-radius_X(), getPosition().y) );
//        m_velocity.x *= -1;
//        CCLOG("LEFTLEFTLEFTLEFT "); 
//    
//    }
//    else if(getPosition().y < m_nRect.origin.y+ m_nRect.size.height  +radius_Y() && getPosition().x > m_nRect.origin.x && getPosition().x< m_nRect.origin.x + m_nRect.size.width){
//        setPosition( ccp(getPosition().x, m_nRect.origin.y+ m_nRect.size.height  - radius_Y()) );
//        m_velocity.y *= -1;
//        CCLOG("UPUPUPUPUPUPUPUPUPUPUPUp");
//    }else if (getPosition().y > m_nRect.origin.y- radius_Y() && getPosition().x> m_nRect.origin.x && getPosition().x< m_nRect.origin.x+ m_nRect.size.width){
//        
//        setPosition( ccp(getPosition().x, m_nRect.origin.y- radius_Y()) );
//        m_velocity.y *= -1;
//        CCLOG("DOWNDOWNDOWNDOWNDOWNDOWN");
//        
//    }
//
   
     
    if (abs(int(m_velocity.x )) > 70) {
        m_velocity.x = arc4random()%30 + 20;
    }
    
    if (abs(int(m_velocity.y ))> 60.0f) {
        m_velocity.y = arc4random()%30 + 15;
    }
        
    accelerlator = (int) delta;
    int count = this->randomMove();
    switch (count) {
        case 10:
            m_velocity.x *=-1.03;
            m_velocity.y *=1.0012;
            break;
        case 20:
            m_velocity.x *= -1.13;
            m_velocity.y *=-1.12;
            break;
        case 30:
            m_velocity.x *= -0.98;
            m_velocity.y *= 0.95;
            break;
        case 40:
            m_velocity.x *= 0.89;
            m_velocity.y *=-0.99;
            break;
        default:
            break;
    }
   
    
    
}
int Bee::randomMove(){
    
    int random_count = 0;
    random_count =(int) arc4random()%50;
    return random_count;
    
 }

void Bee::runFlyAction(){
 
   
    CCAnimation* animation = m_nGame->createArray((char*)"fly", 3);
 
    CCAnimate* ani = CCAnimate::create(animation);
    this->runAction(ani);
    
}