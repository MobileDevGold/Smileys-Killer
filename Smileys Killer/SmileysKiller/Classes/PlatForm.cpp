//
//  Bee.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#include "PlatForm.h"
PlatForm::PlatForm(){
    
}

PlatForm::~PlatForm(){
    
}

PlatForm* PlatForm::body(){
    
    PlatForm* honest = PlatForm::create();
    
    
    return honest;
}
void PlatForm:: initWithGame(Game *game , int nIndex){
    m_nGame = game;
    m_nIndex = nIndex;
    m_nPlatFormStaus = kTagHeroNon;
}
float PlatForm::radius_X()
{
    return getTexture()->getContentSize().width / 2;
}

float PlatForm::radius_Y()
{
    return getTexture()->getContentSize().height / 2;
}
CCRect PlatForm:: Rect(){
    
    CCRect rect = CCRectMake(getPosition().x - getContentSize().width / 2, getPosition().y - getContentSize().height / 2, getContentSize().width, getContentSize().height);
    return rect;
}
void PlatForm::move(float delta)
{
    float POS = randomPos();
   
    m_nRect = m_nGame->m_nplayer->getHeroRect();
    CCPoint gamePos = m_nGame->m_nplayer->getPosition();
   
    
    this->setPosition( ccpAdd(getPosition(), ccpMult(m_velocity, delta)) );
    if (getPosition().x > POS)
    {
        setPosition( ccp(POS, getPosition().y) );
        m_velocity.x *= -1;
    }else if(getPosition().x < 0){
        setPosition( ccp( radius_X(), getPosition().y) );
        m_velocity.x *= -1;

    }
    
    if (m_nRect.intersectsRect(Rect())) {
        
        if (getPosition().y > gamePos.y ) {
            m_nGame->m_nplayer->setStatus(kTagPlatformUp);
            m_nPlatFormStaus = kTagHeroUp;
            
//            m_nGame->m_nplayer->setPosition(ccp(gamePos.x, getPosition().y - Rect().size.height));
//            CCLOG("kTagPlatformUp");
       
        }else if (getPosition().y < gamePos.y){
            
            m_nGame->m_nplayer->setStatus(kTagPlatformDown);
            m_nPlatFormStaus = kTagHeroDown;
//            m_nGame->m_nplayer->setPosition(ccp(getPosition().x, getPosition().y +m_nRect.size.height /2 +5));
//             CCLOG("kTagPlatformDown");
            
        }else if(getPosition().x < gamePos.x){
            
            m_nGame->m_nplayer->setStatus(kTagzPlatformLeft);
            m_nPlatFormStaus = kTagzHeroLeft;
//            CCLOG("kTagPlatformLeft");
           
        }else if(getPosition().x > gamePos.x){
           
            m_nGame->m_nplayer->setStatus(kTagPlatformRight);
            m_nPlatFormStaus = kTagHeroRight;
//            CCLOG("kTagPlatformRight");

           
        }
    }
                 
}

float PlatForm::randomPos(){
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    float posX = size.width / 2 -arc4random()% 100 + 80;
    
    return posX;
    
    
    
}
 
 