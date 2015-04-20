//
//  GameScene.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#include "GameScene.h"
#include "Hero.h"
#include "Bee.h"
#include "SettingScene.h"
#include "TitleScene.h"
#include "Bullets.h"
#include "EnemyRobot.h"
#include "SimpleAudioEngine.h"
#include "Global.h"
#include "Monster.h"
#include "VisibleRect.h"
#include "GameSuccess.h"

USING_NS_CC;
using namespace CocosDenshion;


Game::Game(){
    
}

Game::~Game(){
   
     
    if (_arryBee) {
        _arryBee->release();
        _arryBee = NULL;
    }
    
    if (_arryBullets) {
        _arryBullets->release();
        _arryBullets= NULL;
    }
    
    if (_arryCloudy) {
        _arryCloudy->release();
        _arryCloudy = NULL;
    }
    
    if (_arryMonsters) {
        _arryMonsters->release();
        _arryMonsters = NULL;
    }
    if (_arryExplode) {
        _arryExplode->release();
        _arryExplode = NULL;
    }
    
    
    this->removeAllChildren();
     
}

CCScene* Game::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Game *layer = Game::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Game::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
     
    VisibleSize = CCDirector::sharedDirector()->getWinSize();
 
    this->setTouchEnabled(true);
    this->initWithGame();
    return true;
}

#pragma mark - Init Object
////////////////////////////////////////Init Object///////////////////////////////////////////
void Game::initWithGame(){
    
 
    
   
    this->getLevelInfo();
    this->initWithGameBackground();
    this->initWithVarible();
    this->startCloud();
    this->initWithAnimation();
    this->initWithEnemyRobot();
    this->initBee();
    this->makeMonster();
    this->initJoyStick();
    this->makePlatForm();
    this->initWithMenu();
    appSettings->playBgm();
    
}

void Game::initWithGameBackground(){
    
    char file_sky[0x50] = {0};
    char file_city[0x50] = {0};
   
    switch (m_nLevel) {
        case 1:
            sprintf(file_sky, "sky-orange%s.png" , g_deviceType);
            sprintf(file_city, "Cityscape%s.png" , g_deviceType);
            break;
        case 2:
            sprintf(file_sky,"BlueSky%s.png", g_deviceType);
            sprintf(file_city, "Night%s.png" , g_deviceType);
            break;
        case 3:
            sprintf(file_sky,"sky-orange%s.png", g_deviceType);
            sprintf(file_city, "Cityscape%s.png" , g_deviceType);
            break;
        case 4:
            sprintf(file_sky,"sky-orange%s.png", g_deviceType);
            sprintf(file_city, "Cityscape%s.png" , g_deviceType);
            break;
        case 5:
            sprintf(file_sky,"sky-orange%s.png", g_deviceType);
            sprintf(file_city, "Cityscape%s.png" , g_deviceType);
            break;
        default:
            break;
    }
    
    CCSprite* sky = CCSprite::create(file_sky);
    CCLOG("13213213213%s" , file_sky);
    sky->setPosition(ccp(VisibleSize.width / 2, VisibleSize.height / 2));
    addChild(sky);
    
    CCSprite* night = CCSprite::create(file_city);
    night->setPosition(ccp(VisibleSize.width / 2, VisibleSize.height / 3));
    night->setScale(1);
    addChild(night);


}
void Game::initWithMenu(){
    
    char file[0x50] = {0};
    sprintf(file, "left_arrow%s.png" , g_deviceType_);
    
    CCMenuItemImage* back = CCMenuItemImage::create(file, file, this, menu_selector(Game::backMainMenu));
    back->setPosition(CCPointMake(60.0f*g_fScalX , VisibleSize.height - 40));
    back->setScale(g_fScaleX_);
    
    
    sprintf(file, "bomb%s.png" ,g_deviceType_);
    CCMenuItemImage* bomb = CCMenuItemImage::create(file, file, this, menu_selector(Game::smartBomb));
    bomb->setPosition(CCPointMake(VisibleSize.width / 2 + 160 , VisibleSize.height - 35));
 

    
    CCMenu* menu = CCMenu::create(back,bomb,NULL);
    menu->setPosition(CCPointZero);
    addChild(menu);
    
    sprintf(file , "Coin%s.png" , g_deviceType_);
    CCSprite* coin = CCSprite::create(file);
    coin->setPosition(ccp(VisibleSize.width / 2 - 120, VisibleSize.height - 40));
    addChild(coin);
    
    CCLabelTTF* levels = CCLabelTTF::create("Level:", "Arial", 30);
    levels->setPosition(ccp(VisibleSize.width / 2 + 40, VisibleSize.height - 40));
    levels->setColor(ccBLUE);
    addChild(levels);
    
    sprintf(file, "%d" , m_nBombCount);
    m_lBombLabel = CCLabelTTF::create(file, "Arial", 30);
    m_lBombLabel->setPosition(ccp(VisibleSize.width / 2 + 200, VisibleSize.height - 40));
    m_lBombLabel->setColor(ccYELLOW);
    addChild(m_lBombLabel);
    
    char score[0x50] = {0};
    sprintf(score, "%d" , m_nGameScore);
    m_lCoinLabel = CCLabelTTF::create(score, "Arial", 30);
    m_lCoinLabel->setPosition(ccp(VisibleSize.width / 2 - 60 , VisibleSize.height - 40));
    m_lCoinLabel->setColor(ccYELLOW);
    addChild(m_lCoinLabel);
    
    sprintf(score, "%d" , m_nLevel);
    m_lLevelLabel = CCLabelTTF::create(score, "Arial", 30);
    m_lLevelLabel->setPosition(ccp(VisibleSize.width / 2 + 100 , VisibleSize.height - 40));
    m_lLevelLabel->setColor(ccYELLOW);
    addChild(m_lLevelLabel);
    
}
void Game::initWithVarible(){
    
    _arryCloudy = new CCArray();
    _arryBee = new CCArray();
    _arryBullets = new CCArray;
    _arryMonsters = new CCArray();
    _arryExplode = new CCArray();
    _arryEnemyBullets = new CCArray();
    _arryPlatForm = new CCArray();

    m_bRectContains = false;
    m_bMove = false;
    m_nHeroDirection = false;
    m_nTemp = 0;
    timeprog = 10.0f;
 
    m_nBombCount = 3;
 
    m_nTempCount = 0;
    m_nEnemyBulletsCount = 5;
 
    ACTIONENABLE = false;
 
    
    _arryPoint = CCPointArray::create(5);
    CCPoint pos1 = CCPointMake(VisibleSize.width / 2 +100, VisibleSize.height / 2 - 20);
    _arryPoint->addControlPoint(pos1);
    CCPoint pos2 = CCPointMake( VisibleSize.width / 2 +50, VisibleSize.height  / 2 - 80);
    _arryPoint->addControlPoint(pos2);
    CCPoint pos3 = CCPointMake( VisibleSize.width / 2 +150, VisibleSize.height / 2 - 50);
    _arryPoint->addControlPoint(pos3);
    CCPoint pos4 = CCPointMake( VisibleSize.width / 2 +80, VisibleSize.height - 200);
    _arryPoint->addControlPoint(pos4);
    CCPoint pos5 = CCPointMake( VisibleSize.width / 2 +120, VisibleSize.height - 150);
    _arryPoint->addControlPoint(pos5);
    
  
   
    
}
void Game::initWithAnimation(){
    
    stopAnimation = createarray((char*)"place", 3);
    walkAnime = createarray((char*)"run", 11);
    
    fireAnime = createarray((char*)"Fire", 3);
    enemyRobot = createarray((char*)"gun", 9);
    honest = createArray((char*)"bee", 3);
    
    char file[0x05] = {0};
    sprintf(file, "place1%s.png" , g_deviceType_);
    m_nplayer =Hero::hero();
    m_nplayer->initWithGame(this, 3, 1, CCPointMake(VisibleSize.width / 2 -100  , VisibleSize.height / 2 - 100) , CCPointMake(VisibleSize.width / 2 - 130  , VisibleSize.height / 2 - 60 ));
    m_nplayer->initWithFile(file);
    m_nplayer->setPosition(ccp(VisibleSize.width / 2 - 100  , VisibleSize.height / 2 - 100 ));
    m_nplayer->setLife(5);
    m_nplayer->setStatus(kTagPlatformStatic);
    m_nplayer->runStatic();
    addChild(m_nplayer);
 
 
    
    
}
void Game::initWithEnemyRobot(){
    
    char file[0x05] = {0};
    sprintf(file, "gun1%s.png" , g_deviceType_);

    enemy_r = EnemyRobot::body();
    enemy_r->initWithFile(file);
    enemy_r->setPosition(ccp(VisibleSize.width - 80 , VisibleSize.height / 2 - 100));
    addChild(enemy_r);
    
     
    enemy_l = EnemyRobot::body();
    enemy_l->initWithFile(file);
    enemy_l->setPosition(ccp(VisibleSize.width - 30 , VisibleSize.height / 2 - 100 ));
    addChild(enemy_l);
    
    
    CCAnimate* anim_r = CCAnimate::create(enemyRobot);
    enemy_r->runAction(anim_r);
    CCAnimate* anim_l = CCAnimate::create(enemyRobot);
    enemy_l->runAction(anim_l);
}
 
void Game::initBee(){
    
    schedule(schedule_selector(Game::makeBee), 0.1f);
    schedule( schedule_selector(Game::doStep));
    
    
}
void Game::getLevelInfo(){
    m_nLevel = appSettings->getLevel();
 
    
    if (m_nLevel == 0) {
        m_nLevel = 1;
        appSettings->setLevel(m_nLevel);
    }else if(m_nLevel > 5){
        m_nLevel = 1;
         appSettings->setLevel(m_nLevel);
    }
 
     CCLOG("Level Level Level == %d" , m_nLevel);
    m_nBeeCount = 6;
    m_nMonsterCount = 3;
    m_nGameScore = 0;
    m_nGamePassScore = 1000*m_nLevel;
    
}
void Game:: initJoyStick(){
    
    char file[0x50] = {0};
    char file_sel[0x50] = {0};
    
    sprintf(file, "btn_left_arrow%s.png" , g_deviceType_);
//    sprintf(file_sel, "btn_left_arrow_sel%s.png" , g_deviceType_);
    
    CCMenuItemImage* left = CCMenuItemImage::create(file, file, this, menu_selector(Game::leftDierction));
    left->setPosition(ccp(VisibleSize.width / 2 - 220 ,40));
    left->setScale(g_fScaleX_);
   
    sprintf(file, "btn_right_arrow%s.png" , g_deviceType_);
//    sprintf(file_sel, "btn_right_arrow_sel%s.png" , g_deviceType_);
    CCMenuItemImage* right = CCMenuItemImage::create(file, file, this, menu_selector(Game::rightDirection));
    right->setPosition(ccp(VisibleSize.width / 2 - 150, 40));
    right->setScale(g_fScaleX_);
    
    sprintf(file, "btn_jump%s.png" , g_deviceType_);
    sprintf(file_sel, "btn_jump_sel%s.png" , g_deviceType_);
    CCMenuItemImage* jump = CCMenuItemImage::create(file, file, this, menu_selector(Game::jumpDirection));
    jump->setPosition(ccp(VisibleSize.width / 2 -187, 75));
    jump->setScale(g_fScaleX_);
   
    sprintf(file, "shoot_btn%s.png",g_deviceType_);
    CCMenuItemImage* fire = CCMenuItemImage::create(file, file, this, menu_selector(Game::fire));
    fire->setPosition(ccp(VisibleSize.width / 2 - 185, 40));
    fire->setScale(g_fScaleX_);
    CCMenu* controllMenu = CCMenu::create(left,right,jump,fire,NULL);
    controllMenu->setPosition(CCPointZero);
    addChild(controllMenu);
    
}
void Game::makeBee(cocos2d::CCObject *pSender){
    m_nTemp++;
    if (m_nTemp > m_nBeeCount) {
        m_nTemp = 0;
        this->unschedule(schedule_selector(Game::makeBee));
        return;
    }
    
    float pos_X = 0;
    float pos_Y = 0;
    int px = (int) 150;
    int py = (int) 80 ;
    
    pos_X =arc4random()% px + VisibleSize.width / 2;
    pos_Y = arc4random()% py + VisibleSize.height / 2;
    
    
    float vel_x;
    float vel_y;
    int direction = 1;
    vel_x = (float)(arc4random()%20 + 30);
    vel_y = (float)(arc4random()%15 + 75);
    
    if (vel_x > 25) {
        direction = 1;
    }else if (vel_y >20){
        direction = -1;
    }else if(vel_x >15){
        direction = -1;
    }else if(vel_y >30){
        direction = 1;
    }
    
    char file[0x05] = {0};
    sprintf(file, "bee1%s.png" , g_deviceType_);
    m_nBee = Bee::body();
    m_nBee->initWithFile(file);
    m_nBee->initWithGame(this);
    m_nBee->setPosition(CCPointMake(pos_X, pos_Y));
    m_nBee->setVelocity(ccp(vel_x, -vel_y));
    m_nBee->setRect(getPlayerBoundingBox());
    m_nBee->setScale(1);
    m_nBee->setScore(100);
    m_nBee->runFlyAction();
    addChild(m_nBee);
    _arryBee->addObject(m_nBee);
    
}
void Game::makeMonster(){
    
    float scal = 2.0f;
   
    
    m_nMonsterCount = getMonsterCount();
       for (int i = 0; i< m_nMonsterCount; i++) {
        CCPoint pos = _arryPoint->getControlPointAtIndex(i);
        char file[0x50] = {0};
                  
           float vel_x;
           float vel_y;
           int direction = 1;
           vel_x = (float)(arc4random()%20 + 30);
           vel_y = (float)(arc4random()%15 + 75);
           
           if (vel_x > 25) {
               direction = 1;
           }else if (vel_y >20){
               direction = -1;
           }else if(vel_x >15){
               direction = -1;
           }else if(vel_y >30){
               direction = 1;
           }
           
           if (i == 0 || i == 3 || i == 4 ) {
                sprintf(file , "smiley2%s.png" , g_deviceType_);
               scal = 2.0f;
           }else{
               sprintf(file , "smiley1%s.png" , g_deviceType_);
               scal = 1.0f;
           }
        
        Monster* monster = Monster::body();
        
        monster->initWithFile(file);
        monster->setPosition(pos);
        monster->setScale(scal);
        monster->setVelocity(CCPointMake(vel_x, vel_y));
        monster->m_nLife = 3;
           if (i>0) {
               monster->m_nLife = 1;
           }
            
        monster->runFlyAction();
        monster->randomMove();
           if (i == 0 || i == 3 || i== 4) {
               monster->setScore(200);
               CCAnimation* smiler = createarray((char*)"smiley", 3);
               CCAnimate* animation = CCAnimate::create(smiler);
               monster->runAction(animation);
               monster->m_nLife = 5;
           }else{
               monster->setScore(100);
           }
        monster->setBounds(CCRectMake(pos.x, pos.y, 100, 90));
           
        addChild(monster);
        _arryMonsters->addObject(monster);
    }
   
    
    
}
int Game:: getMonsterCount(){
    int count = 0;
    switch (m_nLevel) {
        case 1:
            count = 3;
            break;
        case 2:
            count = 3;
            break;
        case 3:
            count = 5;
            break;
        case 4:
            count = 4;
            break;
        case 5:
            count =7;
        default:
            break;
    }
    
    return count ;
}
void Game::makeBulletes(CCObject* pSender){
    
    m_nTempCount++;
    if (m_nTempCount > m_nEnemyBulletsCount) {
        m_nTempCount = 0;
        unschedule(schedule_selector(Game::makeBulletes));
        return;
    }
    appSettings->playEffect("bullet.wav");
    
    CCPoint pos = enemy_l ->getPosition();
    Bullets* bullet = Bullets::body();
    char file[0x60] = {0};
    sprintf(file, "Bullet1%s.png" , g_deviceType_);
    bullet->initWithFile(file);
    bullet->setPosition(pos);
    bullet->setScale(2.0f);
    bullet->runEnemyAction();
    addChild(bullet);
    
    pos = enemy_r ->getPosition();
    Bullets* bullet1 = Bullets::body();
    sprintf(file, "Bullet1%s.png" , g_deviceType_);
    bullet1->initWithFile(file);
    bullet1->setPosition(pos);
    bullet1->setScale(2.0f);
    bullet1->runEnemyAction();
    addChild(bullet1);

    _arryEnemyBullets->addObject(bullet1);

}
void Game:: makeBulletes_Robot(){
    
    CCLOG("Make Bulletes");
    
    appSettings->playEffect("bullet.wav");
    CCAnimation* animation = createSingle((char*)"Fire", 3);
    CCAnimate* ani = CCAnimate::create(animation);
    
    m_nplayer->runAction(ani);
    CCPoint pos = m_nplayer->getPosition();
    Bullets* bullet = Bullets::body();
    char file[0x60] = {0};
    sprintf(file, "Bullet1%s.png" , g_deviceType_);
    bullet->initWithFile(file);
    bullet->setPosition(pos);
    bullet->setDirection(m_nHeroDirection);
    bullet->runMoveAction();
    addChild(bullet);
    _arryBullets->addObject(bullet);

}

void Game::makePlatForm(){
    
    
    for (int i = 0; i< 3; i++) {
        char file[0x60] = {0};
        sprintf(file, "grill%s.png",g_deviceType_);
        float posY = arc4random() % 130 + 80;float posR = arc4random() % 50+ 50;
        PlatForm* m_nPlatform = PlatForm::body();
        m_nPlatform->initWithFile(file);
        m_nPlatform->initWithGame(this , i);
        m_nPlatform->setPosition(ccp(3.0f,posY));
        m_nPlatform->setVelocity(ccp(posR,5.0f));
        addChild(m_nPlatform);
        _arryPlatForm->addObject(m_nPlatform);

    }
}

# pragma mark - Step Time
/////////////////////////////////////////////////step Time///////////////////////////
void Game::doStep(float delta){
    
    if (m_nplayer->getPosition().y < VisibleSize.height / 2 - 100) {
      
        m_nplayer->setPosition(ccp(m_nplayer->getPosition().x , VisibleSize.height / 2 - 100));
        if (m_nplayer->getPosition().y ==VisibleSize.height / 2 - 100 ) {
            ACTIONENABLE = false;
        }
    }
    
    if (m_nplayer->lifeBar->getPosition().y < VisibleSize.height / 2 - 60) {
       
        m_nplayer->lifeBar->setPosition(ccp(m_nplayer->lifeBar->getPosition().x  , VisibleSize.height / 2 - 60));
        m_nplayer->backBar->setPosition(ccp(m_nplayer->backBar->getPosition().x  ,VisibleSize.height / 2 - 60));

    }
    
    if (m_nplayer->getPosition().x > VisibleSize.width / 2 && m_nplayer->getPosition().y < VisibleSize.height / 2) {
        schedule(schedule_selector(Game::makeBulletes), 1.0f);
 
    }
    
     
    
    for (int i = 0; i< _arryPlatForm->count(); i++) {
        PlatForm* plat = (PlatForm*) _arryPlatForm->objectAtIndex(i);
        plat->move(delta);
    }
    
    for (int i = 0 ; i< _arryBee->count(); i++) {
        Bee* temp_ = (Bee*) _arryBee->objectAtIndex(i);
        temp_->move(delta);
        CCRect beeRect = temp_->Rect();
        
        for (int j = 0; j < _arryBullets->count(); j++) {
            Bullets* temp = (Bullets*)_arryBullets->objectAtIndex(j);
            CCPoint pos =temp->getPosition();
         
            if (beeRect.containsPoint(pos)) {
                getScore(temp_->getScore());
                this->removeChild(temp, true);
                temp_->stopAllActions();
                removeChild(temp_);
                _arryBullets->removeObjectAtIndex(j);
                _arryBee->removeObjectAtIndex(i);
            }
        }
    }
    
    for (int i = 0 ; i< _arryMonsters->count(); i++) {
        Monster* temp_monster = (Monster*) _arryMonsters->objectAtIndex(i);
        temp_monster->move(delta);
        CCRect monsterRect = temp_monster->Rect();
        
        for (int j = 0; j < _arryBullets->count(); j++) {
            Bullets* temp = (Bullets*)_arryBullets->objectAtIndex(j);
            CCPoint pos =temp->getPosition();
            
            if (monsterRect.containsPoint(pos)) {
                temp_monster->m_nLife--;
               
                if (temp_monster->m_nLife == 0) {
                    Exploding(pos);
                    getScore(temp_monster->getSCore());
                    temp_monster->stopAllActions();
                    removeChild(temp_monster);
                    _arryMonsters->removeObjectAtIndex(i);

                }
                
                this->removeChild(temp, true);
                _arryBullets->removeObjectAtIndex(j);
            }
        }
    }

    for (int i = 0 ; i< _arryExplode->count(); i++) {
        CCSprite* temp_ = (CCSprite*) _arryExplode->objectAtIndex(i);
 
        CCRect playerRect = m_nplayer->getHeroRect();
        
        if (playerRect.containsPoint(temp_->getPosition())) {
            m_nplayer->m_nLife --;
        }
        
    }
    
    CheckHeroRect();
    CheckJoystickRect();
    CheckGameStatus();
}
//////////////////////////////////////////////////////////////////////////
void Game:: Exploding(CCPoint nPos){
    
    char file[0x50] = {0};
    sprintf(file, "Explosion_Smiley%s.png" , g_deviceType_);
    CCSprite* destroy = CCSprite::create(file);
    destroy->setPosition(getExplodePosition(nPos));
    CCFadeTo* fade_ = CCFadeTo:: create(0.5f, 0.0f);
    destroy->runAction(fade_);
    addChild(destroy);
    
    
    for (int i = 0 ; i < 5; i++) {
       
        CCPoint m_nLocation = getExplodePosition(nPos);
        sprintf(file, "explode%s.png" , g_deviceType_);
        CCSprite* explod = CCSprite::create(file);
        explod->setPosition(m_nLocation);
        CCFadeTo* fade = CCFadeTo:: create(5.0f, 0.0f);
        explod->runAction(fade);
       
        addChild(explod);
        
    }
}

CCPoint Game:: getExplodePosition(CCPoint nPos){
    
    float pos_x =nPos.x- (float)(arc4random() % 70);
    float pos_y =nPos.y-(float)(arc4random() % 50) ;
    
    CCPoint pos = CCPointMake(pos_x, pos_y);
    return pos;
    
    
}

void Game:: CheckHeroLife(cocos2d::CCPoint nPos){
    
    timeprog--;
    if (timeprog < 0) {
        
        stopAllActions();
        CCLayerColor* gameover = GameOver::create();
        addChild(gameover);
         gameOver();
 
        return;
    }
    CCLOG("%f",timeprog/30);
    m_nplayer->lifeBar->setScaleX(1.0f*timeprog/(10));
    getScore(-50);
    
}
void Game:: CheckHeroRect(){
    
    if (m_nplayer->getStatus() == kTagPlatformUp) {
        CCLOG("kTagPlatformUp");
        m_nplayer->runFall();
    }else if(m_nplayer->getStatus() == kTagPlatformDown){
        if (ACTIONENABLE == true) {
            return;
        }
        for (int i = 0; i<_arryPlatForm->count(); i++) {
            PlatForm* temp = (PlatForm*) _arryPlatForm->objectAtIndex(i);
            if (temp->getContains() == kTagHeroDown) {
                m_nplayer->setPosition(ccp(temp->getPosition().x, temp->getPosition().y+m_nplayer->getContentSize().height / 2 +10));
                m_nplayer->lifeBar->setPosition(ccp(m_nplayer->getPosition().x -30, m_nplayer->getPosition().y+40));
                m_nplayer->backBar->setPosition(ccp(m_nplayer->getPosition().x -30, m_nplayer->getPosition().y+40));
                m_nplayer->setStatus(kTagPlatformStatic);
            }
        }
        CCLOG("kTagPlatformDown");
    }else if(m_nplayer->getStatus() == kTagPlatformRight){
        
        CCLOG("kTagPlatformRight");
    }else if(m_nplayer->getStatus() == kTagzPlatformLeft){
        CCLOG("kTagzPlatformLeft");
    }
}

void Game:: CheckJoystickRect(){
    
    if (m_nplayer->getPosition().x < VisibleSize.width / 2 -100 && m_nplayer->getPosition().y < VisibleSize.width / 2 - 200+ m_nplayer->getContentSize().width / 2) {
        m_nplayer->setPosition(ccp(VisibleSize.width / 2 -100, m_nplayer->getPosition().y));
        m_nplayer->lifeBar->setPosition(ccp(m_nplayer->getPosition().x -30, m_nplayer->getPosition().y + 40));
        m_nplayer->backBar->setPosition(ccp(m_nplayer->getPosition().x -30, m_nplayer->getPosition().y + 40));
    }
}

void Game:: CheckGameStatus(){
    
    if (_arryBee->count() == 0 && _arryMonsters->count() == 0) {
        unscheduleAllSelectors();
        levelCompleted();
    }else{
        return;
    }
}

void Game:: levelCompleted(){
    
    CCDirector::sharedDirector()->stopAnimation();
    GameSuccess* success = GameSuccess::create();
    addChild(success);
   
    
}
void Game::gameOver(){
    
    unscheduleAllSelectors();
    stopAllActions();
    for (int i = 0 ; i< _arryBee->count(); i++) {
        CCDirector::sharedDirector()->stopAnimation();
        Bee* bee = (Bee*)_arryBee->objectAtIndex(i);
       
        bee->stopAllActions();
         
        
    }
    
    for (int i = 0 ; i<_arryMonsters->count(); i++) {
        Monster* monster = (Monster*) _arryMonsters->objectAtIndex(i);
        monster->stopAllActions();
       
        
    }
    m_nplayer->removeAllChildren();
    

}
#pragma mark - Animation Settings
///////////////////////////////////////////////////////Animation Frame Setting/////////////////////////////////////
CCAnimation* Game::createarray(char* name ,int frameCount)
{
    CCAnimation* animation = CCAnimation::create();
    for (int i = 1; i<frameCount; i++) {
        char file[100] = {0};
        sprintf(file, "%s%d%s.png" , name ,i,g_deviceType_);
        CCLOG("Character = %s"  , file);
        animation->addSpriteFrameWithFileName(file);
    }
    
    animation->setDelayPerUnit(0.15f);
    animation->setLoops(-1);
    
    return animation;
}
CCAnimation* Game::createArray(char* name ,int frameCount)
{
    CCAnimation* animation = CCAnimation::create();
    for (int i = 1; i<frameCount; i++) {
        char file[100] = {0};
        sprintf(file, "%s%d%s.png" , name , i,g_deviceType_);
        animation->addSpriteFrameWithFileName(file);
    }
    
    animation->setDelayPerUnit(0.09f);
    animation->setLoops(-1);
    
    return animation;
   
}
CCAnimation* Game::createSingle(char* name ,int frameCount)
{
    CCAnimation* animation = CCAnimation::create();
    for (int i = 1; i<frameCount; i++) {
        char file[100] = {0};
        sprintf(file, "%s%d%s.png" , name , i,g_deviceType_);
        animation->addSpriteFrameWithFileName(file);
    }
    
    animation->setDelayPerUnit(0.1f);
    animation->setLoops(0.5f);
    
    return animation;
}

void Game::getScore(int nScore){
    
    char score[0x50] = {0};
    m_nGameScore +=nScore;
    sprintf(score, "%d" , m_nGameScore);
    if (m_nGameScore < 0) {
        sprintf(score, "%d" , 0);
    }
    m_lCoinLabel->setString(score);
}
#pragma marl - Menu Event
////////////////////////////////////////////Menu Event////////////////////////////////////////////////////////////////
void Game::backMainMenu(cocos2d::CCObject *pSender){
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, Title::scene()));
}

void Game::smartBomb(cocos2d::CCObject *pSender){
    
    m_nBombCount--;
    if (m_nBombCount < 0) {
        return;
    }

    char str[0x50] = {0};
    sprintf(str, "%d" , m_nBombCount);
    m_lBombLabel->setString(str);
        

}
#pragma mark - Action Start
////////////////////////////////////////////Action Init//////////////////////////////////////////////////////////////////
void Game::startCloud(){
    
    for (int i = 0; i< 100; i++) {
        
        char file[100] = {0};
        sprintf(file, "Cloud%s.png" , g_deviceType);
        CCSprite* m_nCloudy = CCSprite::create(file);
        m_nCloudy->setPosition(ccp(VisibleSize.width / 2+VisibleSize.width*i, VisibleSize.height / 2 + 45));
        m_nCloudy->setScaleY(0.7f);
        this->addChild(m_nCloudy);
        _arryCloudy->addObject(m_nCloudy);
    }
    
    
    for (int i = 0; i<_arryCloudy->count(); i++) {
        CCSprite* temp = CCSprite::create();
        temp = (CCSprite*)_arryCloudy->objectAtIndex(i);
        CCMoveTo* move = CCMoveTo::create(100+i*100, ccp(-VisibleSize.width, VisibleSize.height / 2+45));
        temp->runAction(move);
    }
    
    schedule(schedule_selector(Game:: checkCloud) , 1.0f);
    
}
void Game:: checkCloud(CCObject* pSender){
    
    CCSprite* temp = CCSprite::create();
    temp = (CCSprite*)_arryCloudy->lastObject();
    if (temp->getPosition().x < VisibleSize.width / 2) {
        CCLOG("End Cloudy");
    }
}

void Game:: leftDierction(CCObject *pSender){
    
        
    if (m_nHeroDirection == true) {
        
        if (m_nplayer->getPosition().x < VisibleRect::left().x + m_nplayer->getContentSize().width) {
            m_nplayer->setPosition(ccp( VisibleRect::left().x + m_nplayer->getContentSize().width , m_nplayer->getPosition().y));
            return;
        }

        
        CCAnimation* temp = createArray((char*)"run", 11);
        CCAnimate* ani_l = CCAnimate::create(temp);
        ani_l->setDuration(0.1f);
        m_nplayer->runAction(ani_l);
        
        CCMoveBy* by = CCMoveBy::create(0.3f, CCPointMake(-30.0f, 0.0f));
        m_nplayer->runAction(by);
        
        CCMoveBy* by1 = CCMoveBy::create(0.3f, CCPointMake(-30.0f, 0.0f));
        m_nplayer->lifeBar->runAction(by1);
        
        CCMoveBy* by2 = CCMoveBy::create(0.3f, CCPointMake(-30.0f, 0.0f));
        m_nplayer->backBar->runAction(by2);
        
        ACTIONENABLE = true;
        m_nplayer->runFall();

    }
    if (m_nHeroDirection == false) {
        m_nHeroDirection = true;
    }
    m_nplayer->setFlipX(m_nHeroDirection);

    
}
void Game:: rightDirection(CCObject *pSender){
    
       
    if (m_nHeroDirection == false) {
            if (m_nplayer->getPosition().x > VisibleRect::right().x - m_nplayer->getContentSize().width) {
                m_nplayer->setPosition(ccp( VisibleRect::left().x - m_nplayer->getContentSize().width , m_nplayer->getPosition().y));
                return;
            }

        CCAnimation* temp = createArray((char*)"run", 11);
        CCAnimate* ani_r = CCAnimate::create(temp);
        ani_r->setDuration(0.1f);
        m_nplayer->runAction(ani_r);
        
        CCMoveBy* by = CCMoveBy::create(0.3f, CCPointMake(30.0f, 0.0f));
        m_nplayer->runAction(by);
        
        CCMoveBy* by1= CCMoveBy::create(0.3f, CCPointMake(30.0f, 0.0f));
        m_nplayer->lifeBar->runAction(by1);
        
        
        CCMoveBy* by2 = CCMoveBy::create(0.3f, CCPointMake(30.0f, 0.0f));
        m_nplayer->backBar->runAction(by2);
        
        ACTIONENABLE = true;
        m_nplayer->runFall();

    }
    
    if (m_nHeroDirection == true) {
        m_nHeroDirection = false;
    }
    m_nplayer->setFlipX(m_nHeroDirection);

    
}
void Game:: jumpDirection(CCObject *pSender){
    if (m_nplayer->getStatus() == kTagPlatformStatic) {
         m_nplayer->runJump();
    }
    
    return;
      
 
}
void Game:: fire(CCObject *pSender){
   
    CCLOG("Make Bulletes");
    
    appSettings->playEffect("bullet.wav");
    CCAnimation* animation = createSingle((char*)"Fire", 3);
    CCAnimate* ani = CCAnimate::create(animation);
    
    m_nplayer->runAction(ani);
    CCPoint pos = m_nplayer->getPosition();
    Bullets* bullet = Bullets::body();
    char file[0x60] = {0};
    sprintf(file, "Bullet1%s.png" , g_deviceType_);
    bullet->initWithFile(file);
    bullet->setPosition(pos);
    bullet->setDirection(m_nHeroDirection);
    bullet->runMoveAction();
    addChild(bullet);
    _arryBullets->addObject(bullet);

}
#pragma mark - Getter  and Setter
//////////////////////////////////////Getter and Setter////////////////////////////
CCRect Game::getPlayerBoundingBox(){
    
    
    CCLOG("rect rect == %f" , m_nplayer->getHeroRect().size.width);
    CCRect rect = CCRectMake(m_nplayer->getPosition().x - m_nplayer->getContentSize().width / 2, m_nplayer->getPosition().y - m_nplayer->getContentSize().height / 2, m_nplayer->getContentSize().width, m_nplayer->getContentSize().height);
    return rect;
}
#pragma mark - Touch Delegate
//////////////////////////////////////Touch delegate///////////////////////////////
void Game::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event){
    
    CCTouch *touch =(CCTouch*)(touches->anyObject());
	m_nBeginLocation = touch->getLocationInView();
	m_nBeginLocation = CCDirector::sharedDirector()->convertToGL(m_nBeginLocation);
//    m_nplayer->stopAllActions();
//    CCRect rect = m_nplayer->getHeroRect();
//    
//    if (rect.containsPoint(m_nBeginLocation)) {
//        m_bRectContains = true;
//        CCLOG("Contains successfuly");
//        
//    }
//    
//    m_bMove = false;
    
}
void Game::ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *event){
    
    
    
//    if (m_bRectContains == false) {
//        return;
//    }
//    CCTouch *touch =(CCTouch*)(touches->anyObject());
//	m_nMoveLocation= touch->getLocationInView();
//	m_nMoveLocation = CCDirector::sharedDirector()->convertToGL(m_nMoveLocation);
//    m_nplayer->setPosition(m_nMoveLocation);
//    
//    float direct_h;
//    float direct_v;
//    
//    direct_h = m_nMoveLocation.x - m_nBeginLocation.x;
//    direct_v = m_nMoveLocation.y - m_nBeginLocation.y;
//    if (direct_h > 0) {
//        applyPlayAction(MOVE_RIGHT);
//        applyPlayAction(MOVE_DOWN);
//    }else if(direct_h < 0){
//        applyPlayAction(MOVE_LEFT);
//        applyPlayAction(MOVE_UP);
//    }
//    m_bMove = true;
//    
}

void Game::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event){
    
//    CCLOG("Touch Success");
//    
//    CCTouch *touch =(CCTouch*)(touches->anyObject());
//	m_nEndLocation =touch->getLocationInView();
//	//m_nEndLocation = CCDirector::sharedDirector()->convertToGL(m_nEndLocation);
//    m_bRectContains = false;
//    
//   
//    CCAnimation* temp = createarray((char*)"place", 3);
//    CCAnimate* ani = CCAnimate::create(temp);
//    m_nplayer->runAction(ani);
//    
//    if (m_bMove == true){
//        return;
//    }
    makeBulletes_Robot();
    
}
void Game::registerWithTouchDispatcher()
{
	// CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this,0,true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
}

