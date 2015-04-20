//
//  Hero.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

 
#include "Hero.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Global.h"
 
using namespace CocosDenshion;
Hero::Hero(){
    
}

Hero::~Hero(){
    
    
}

Hero* Hero::hero(){
    
    Hero* hero = Hero::create();
    return hero;
}

void Hero::initWithGame(Game *nScene, int nLife, int nType,CCPoint nPos , CCPoint nbarPos){
    
    m_nScene = nScene;
    m_nLife = nLife;
    m_nType = nType;
    m_nPos = nPos;
    m_nbarpos = nbarPos;
    
    char file [0x50] = {0};
    sprintf(file, "bar%s.png" ,g_deviceType_);
    backBar = CCSprite::create(file);
    backBar->setAnchorPoint(ccp(0.0f , 0.5f));
    backBar->setPosition(m_nbarpos);
 
    backBar->setScaleX(1.0f);backBar->setScaleY(1.0f);
    m_nScene->addChild(backBar);

    sprintf(file , "life_bar%s.png" , g_deviceType_);
    lifeBar = CCSprite::create(file);
    lifeBar->setAnchorPoint(ccp(0.0f , 0.5f));
    lifeBar->setPosition(m_nbarpos);
    lifeBar->setScaleX(1.0f);lifeBar->setScaleY(1.0f);
    m_nScene->addChild(lifeBar);
    
    jumpAction = NULL;
    jumpAction_backBar = NULL;
    jumpAction_lifeBar = NULL;
}

void Hero:: setLife(int nLife){
    
    m_nLife = nLife;
    
}

int Hero:: getLife(){
    
    
    return m_nLife;
}

CCRect Hero:: getHeroRect(){
    
    CCRect rect = CCRectMake(getPosition().x- getContentSize().width / 2,  getPosition().y - getContentSize().height / 2, getContentSize().width,getContentSize().height);
    return rect;
    
}
void Hero:: runStatic(){
    staticAction = CCAnimate::create(m_nScene->stopAnimation);
    this->runAction(staticAction);
}
void Hero:: runWalk(){
    walkAction = CCAnimate::create(m_nScene->walkAnime);
    this->runAction(walkAction);
    
   
}

void Hero:: runJump(){
    
    jumpAction = CCJumpTo::create(1.0f, CCPointMake(getPosition().x, m_nPos.y), 100, 1);
    this->runAction(jumpAction);
   
    jumpAction_lifeBar = CCJumpTo::create(1.0f, CCPointMake(getPosition().x-30, m_nbarpos.y), 100, 1);
    lifeBar->runAction(jumpAction_lifeBar);
    jumpAction_backBar = CCJumpTo::create(1.0f, CCPointMake(getPosition().x-30, m_nbarpos.y), 100, 1);
    backBar->runAction(jumpAction_backBar);
    
     
}
void Hero::runFly(){
    
    CCAnimation* animation = m_nScene->createArray((char*)"jump", 3);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.01f);
    flyAction = CCAnimate::create(animation);
    flyAction->setDuration(0.9f);
    
    this->runAction(flyAction);

}
void Hero:: runFall(){
    if (jumpAction != NULL) {
        stopAction(jumpAction);
    }else if(staticAction !=NULL){
        stopAction(jumpAction);
    }
    
    if(jumpAction_backBar !=NULL)
        backBar->stopAction(jumpAction_backBar);
    
    if(jumpAction_lifeBar != NULL)
        lifeBar->stopAction(jumpAction_lifeBar);
 
    CCMoveTo* move = CCMoveTo::create(0.8f, CCPointMake(getPosition().x, m_nPos.y));
    CCMoveTo* move_lifebar = CCMoveTo::create(0.8f, CCPointMake(getPosition().x-30, m_nbarpos.y));
    CCMoveTo* move_backbar = CCMoveTo::create(0.8f, CCPointMake(getPosition().x-30, m_nbarpos.y));
    this->runAction(move);
    lifeBar->runAction(move_lifebar);
    backBar->runAction(move_backbar);
    this->setStatus(kTagPlatformStatic);
    
   
}

 