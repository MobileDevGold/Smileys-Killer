//
//  GameOver.cpp
//  SmileysKiller
//
//  Created by Mikhail Berrya on 10/20/13.
//
//

#include "GameOver.h"
#include "cocos2d.h"
#include "Global.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "AppSettings.h"
USING_NS_CC;

CCScene* GameOver::scene(){
    
    
    CCScene* scene = CCScene::create();
    GameOver* layer = GameOver:: create();
    scene->addChild(layer);
    
    return scene;
}

bool GameOver:: init(){
    
    if ( !CCLayerColor::initWithColor(ccc4(0,0,0,128)))
    {
        return false;
    }
    
    WinSize = CCDirector::sharedDirector()->getWinSize();
    
    initMenu();
    
    
    
    return true;

}

void GameOver::initMenu(){
    
    char file[0x50] = {0};
 
    sprintf(file, "btn_menu%s.png" , g_deviceType_);
    
    
    CCMenuItemImage* main = CCMenuItemImage::create(file, file, this, menu_selector(GameOver::onNext));
    main->setPosition(CCPointMake(WinSize.width / 2 - 100 , WinSize.height / 2 - 40));
 
    
    sprintf(file , "btn_reply%s.png" , g_deviceType_);
 
    CCMenuItemImage* reply = CCMenuItemImage::create(file , file, this, menu_selector(GameOver::onReply));
    reply->setPosition(ccp(WinSize.width / 2+100, WinSize.height / 2 - 40));
     
    
    
    CCMenu* menu = CCMenu::create(main,reply,NULL);
    menu->setPosition(CCPointZero);
    addChild(menu);
    
     
    m_lTitleLabel = CCLabelTTF::create("GameOver", "Arial", 30);
    m_lTitleLabel->setPosition(ccp(WinSize.width / 2 , WinSize.height - 40));
    m_lTitleLabel->setColor(ccRED);
    addChild(m_lTitleLabel);

}

void GameOver::onNext(cocos2d::CCObject *pSender){
    CCDirector::sharedDirector()->startAnimation();
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.5f, Title::scene()));
    
}

void GameOver::onReply(cocos2d::CCObject *pSender){
    CCDirector::sharedDirector()->startAnimation();
    
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}