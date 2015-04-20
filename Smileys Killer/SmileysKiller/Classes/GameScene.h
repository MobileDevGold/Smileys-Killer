//
//  GameScene.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#ifndef __GAME__SCENE__H__
#define __GAME__SCENE__H__

#include <iostream>
#include "cocos2d.h"
#include "EnemyRobot.h"
#include "AppSettings.h" 
#include "PlatForm.h"
#include "GameOver.h"
 

typedef enum {
    MOVE_RIGHT = 0,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN
    
}MOVE_DIRECTION;

class Hero;
class Bee;
 

USING_NS_CC;
class Game: public cocos2d::CCLayer
{
public:
    
    Game();
    ~Game();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    void initWithGame();
    void initWithGameBackground();
    void initWithMenu();
    void initWithAnimation();
    void initWithEnemyRobot();
    void initWithVarible();
    void initBee();
    void getLevelInfo();
    void startCloud();
    void makeMonster();
    void makePlatForm();
    void makeBulletes(CCObject* pSender);
    void makeBulletes_Robot();
 
    void doStep(float delta);
    void Exploding(CCPoint nPos);
    
     
    
    // Game Menu Settings
    void checkCloud(CCObject* pSender);
    void makeBee(CCObject* pSender);
    void backMainMenu(CCObject* pSender);
    void smartBomb(CCObject* pSender);
    
    CCLabelTTF* m_lCoinLabel;
    CCLabelTTF* m_lLevelLabel;
    CCLabelTTF* m_lBombLabel;
    
    // hero contorller
    void initJoyStick();
    void leftDierction(CCObject* pSender);
    void rightDirection(CCObject* pSender);
    void jumpDirection(CCObject* pSender);
    void fire(CCObject* pSender);
    void getScore(int nScore);
    void CheckHeroLife(CCPoint nPos);
    void CheckHeroRect();
    void CheckJoystickRect();
    void CheckGameStatus();
    // Game Status
    void gameOver();
    void levelCompleted();
    
    
    CCPoint getExplodePosition(CCPoint nPos);
    CCRect getPlayerBoundingBox();

    
    Hero* m_nplayer;
    Bee* m_nBee;
    EnemyRobot* enemy_r;
    EnemyRobot* enemy_l;
    AppSettings* appSettings;
  
 
    
    CCArray* _arryCloudy;
    CCArray* _arryBee;
    CCArray* _arryBullets;
    CCArray* _arryMonsters;
    CCArray* _arryExplode;
    CCArray* _arryEnemyRobot;
    CCArray* _arryEnemyBullets;
    CCArray* _arryPlatForm;
   
    CCPointArray* _arryPoint;
    CCAnimation*   createarray (char* name , int framCount);
    CCAnimation*   createArray (char* name , int framCount);
    CCAnimation*   createSingle (char* name , int framCount);
    CCAnimation*   stopAnimation;
    CCAnimation*   walkAnime;
    CCAnimation*   jumpAnime;
    CCAnimation*   fireAnime;
    CCAnimation*   enemyRobot;
    CCAnimation*   honest;
    CCAnimate* placeAnimate;
    
    CCPoint m_nMoveLocation;
    CCPoint m_nEndLocation;
    CCPoint m_nBeginLocation;
    
    
    bool    m_bRectContains;
    bool    m_bMove;
    bool    m_nHeroDirection;
    bool ACTIONENABLE;
   
    int m_nBeeCount;
    int m_nMonsterCount;
    int m_nLevel;
    int m_nBombCount;
    int m_nTemp;
    int m_nTempCount;
    int m_nEnemyBulletsCount;
    int m_nGamePassScore;
    int m_nGameScore;
    int getMonsterCount();
    float timeprog;
    
    
    //Touch define
    void ccTouchesBegan(CCSet* touches, CCEvent* event);
    void ccTouchesMoved(CCSet* touches,CCEvent* event);
    void ccTouchesEnded(CCSet* touches,CCEvent* event);
    void registerWithTouchDispatcher();

       
    
    // implement the "static node()" method manually
    CREATE_FUNC(Game);
protected:
    cocos2d::CCSize  VisibleSize;
    cocos2d::CCPoint origin ; 
    
};

#endif /* __GAME__SCENE__H__*/
