#include "TitleScene.h"
#include "AppMacros.h"
#include "SettingScene.h"
#include "GameScene.h"
#include "Global.h"
#include "AppSettings.h"
USING_NS_CC;


CCScene* Title::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Title *layer = Title::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Title::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    VisibleSize = CCDirector::sharedDirector()->getWinSize();
//   CPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    char file[0x05] = {0};
    sprintf(file, "BlueSky%s.png" , g_deviceType);
    
    CCLOG("backGround Image === %s" , file);
    CCSprite* bg = CCSprite::create(file);
    bg->setPosition(ccp(VisibleSize.width / 2, VisibleSize.height / 2));
    addChild(bg);
    initMenu();

        
    return true;
}

void Title:: initMenu(){
    
    char file[0x05] = {0};
    sprintf(file, "play_btn%s.png" , g_deviceType_);
    CCMenuItemImage* game = CCMenuItemImage::create(file, file, this, menu_selector(Title::menuPlay));
    game->setPosition(ccp(VisibleSize.width / 2, VisibleSize.height / 2 + 135));
    
    sprintf(file, "LeaderBoard%s.png" , g_deviceType_);
    CCMenuItemImage* LeaderBoard = CCMenuItemImage::create(file, file, this, menu_selector(Title::menuLeaderBoard));
    LeaderBoard->setPosition(ccp(VisibleSize.width / 2   , VisibleSize.height / 2  ));
   
    sprintf(file, "setting_btn%s.png" , g_deviceType_);
    CCMenuItemImage* setting = CCMenuItemImage::create(file,file, this, menu_selector(Title::menuSettings));
    setting->setPosition(ccp(VisibleSize.width / 2  , VisibleSize.height / 2 - 125));
   
    
    
    CCMenu* mainMenu = CCMenu::create(game, LeaderBoard, setting, NULL);
    mainMenu->setPosition(CCPointZero);
    mainMenu->setScale(0.5);
    addChild(mainMenu ,4);
    
    
}

void Title:: menuPlay(CCObject *pSender){
    
  CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, Game::scene()));
    
}

void Title:: menuSettings(CCObject *pSender){
    
   
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, SettingView::scene()));
    
}
void Title:: menuLeaderBoard(CCObject *pSender){
    
}


 