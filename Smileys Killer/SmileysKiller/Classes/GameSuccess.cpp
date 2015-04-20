//
//  GameSuccess.cpp
//  SmileysKiller
//
//  Created by Mikhail Berrya on 10/21/13.
//
//

#include "GameSuccess.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "Global.h"
CCScene* GameSuccess::scene(){
    
    CCScene* scene = CCScene::create();
    GameSuccess* layer = GameSuccess::create();
    
    scene->addChild(layer);
    return scene;
}

bool GameSuccess::init(){
    
    if (!CCLayerColor::initWithColor(ccc4(0,0,0,128))){
        return false;
    }
    
    WinSize = CCDirector::sharedDirector()->getWinSize();
    m_nLevel = appSettigns->getLevel();
    initMenu();
    
    
    return true;
}

void GameSuccess::initMenu(){
    
    char file[0x50] = {0};
    char file_sel[0x50] = {0};
    sprintf(file, "btn_next%s.png" , g_deviceType_);
    sprintf(file_sel, "btn_next_sel%s.png" , g_deviceType_);
    
    CCMenuItemImage* next = CCMenuItemImage::create(file, file, this, menu_selector(GameSuccess::onNext));
    next->setPosition(CCPointMake(WinSize.width / 2 - 100 , WinSize.height / 2 - 40));
   
    
    sprintf(file , "btn_reply%s.png" , g_deviceType_);
    sprintf(file_sel, "btn_reply%s.png" , g_deviceType_);
    CCMenuItemImage* reply = CCMenuItemImage::create(file , file_sel, this, menu_selector(GameSuccess::onReply));
    reply->setPosition(ccp(WinSize.width / 2+100, WinSize.height / 2 - 40));
     
    
    
    CCMenu* menu = CCMenu::create(next,reply,NULL);
    menu->setPosition(CCPointZero);
    addChild(menu);
    
    
    m_lTitleLabel = CCLabelTTF::create("Level Completed", "Arial", 30);
    m_lTitleLabel->setPosition(ccp(WinSize.width / 2 , WinSize.height - 40));
    m_lTitleLabel->setColor(ccRED);
    addChild(m_lTitleLabel);

    
}

void GameSuccess::onNext(cocos2d::CCObject *pSender){
    
    CCDirector::sharedDirector()->startAnimation();
    m_nLevel = appSettigns->getLevel();
    m_nLevel++;
    appSettigns->setLevel(m_nLevel);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade ::create(0.5f, Game::scene(), ccYELLOW));
    
}

void GameSuccess:: onReply(cocos2d::CCObject *pSender){
    CCDirector::sharedDirector()->startAnimation();
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade ::create(0.5f, Game::scene(), ccBLUE));
}

