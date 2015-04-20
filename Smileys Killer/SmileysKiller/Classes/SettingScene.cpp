//
//  SettingScene.cpp
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#include "SettingScene.h"
#include "TitleScene.h"
#include "AppMacros.h"
#include "AppSettings.h"
#include "Global.h"
USING_NS_CC;

CCScene * SettingView::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SettingView *layer = SettingView::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

CCLayer* SettingView::layer(){
    SettingView* layer = SettingView::create();
    return layer;
}
SettingView* SettingView::setting(){
    SettingView* layer = SettingView::create();
    return layer;
}
 
bool SettingView::init()
{
    if(!(CCLayer::init())){
        return false;
    }
    
    Winsize = CCDirector::sharedDirector()->getWinSize();
    
    
    AppSettings* app ;
    bgstate = app->getBgSound();
    effectstate = app->geteffectSound();
    
    char file[0x50] = {0};
    sprintf(file, "BlueSky%s.png", g_deviceType);
    CCSprite* pSprite = CCSprite::create(file);
    pSprite->setPosition(ccp(Winsize.width/2, Winsize.height/2));
    this->addChild(pSprite, 0);
    
    sprintf(file, "setting_btn%s.png", g_deviceType_);
    CCSprite* title = CCSprite::create(file);
    title->setPosition(ccp(Winsize.width/2, Winsize.height/2+120));
    this->addChild(title, 0);
    
    
    
    sprintf(file, "sound%s.png" , g_deviceType_);
    CCSprite* soundBtn = CCSprite::create(file);
    soundBtn->setPosition(ccp(Winsize.width / 2-150*g_fScaleX_  , Winsize.height / 2+30 ));
    soundBtn->setScale(g_fScaleX_);
    addChild(soundBtn);
    
    sprintf(file, "effectBtn%s.png" , g_deviceType_);
    CCSprite* effectBtn = CCSprite::create(file);
    effectBtn->setPosition(ccp(Winsize.width / 2-150*g_fScaleX_  , Winsize.height / 2-55  ));
    effectBtn->setScale(g_fScaleX_);
     addChild(effectBtn);
    //background music
    
    sprintf(file, "onBtn%s.png",g_deviceType_);
    on = CCMenuItemImage::create(file, file, this, menu_selector(SettingView::setBackground));
    on->setPosition(ccp( Winsize.width / 2+150  , Winsize.height / 2+65 ));
     
    
    sprintf(file, "off%s.png",g_deviceType_);
    off= CCMenuItemImage::create(file, file, this, menu_selector(SettingView::setBackground));
     
    off->setPosition(ccp(Winsize.width / 2+150  , Winsize.height / 2+65 ));
    
    //effect Music
    sprintf(file, "onBtn%s.png",g_deviceType_);
    printf("%s\n" ,file);
    on_effect = CCMenuItemImage::create(file, file, this, menu_selector(SettingView::setEffect));
    on_effect->setPosition(ccp( Winsize.width / 2+150 , Winsize.height / 2-110 ));
    
    
    sprintf(file, "off%s.png",g_deviceType_);
    printf("%s\n" ,file);
    off_effect= CCMenuItemImage::create(file, file, this, menu_selector(SettingView::setEffect));
 
    off_effect->setPosition(ccp(Winsize.width / 2+150 , Winsize.height / 2-110  ));
    
    //backButton
    sprintf(file, "left_arrow%s.png" , g_deviceType_);
     
    CCMenuItemImage* back = CCMenuItemImage::create(file, file, this, menu_selector(SettingView::backGo));
    back->setPosition(ccp(-150 , Winsize.height +100 ));
    
    sprintf(file, "user%s.png",g_deviceType_);
    printf("%s" ,file);
    invite = CCMenuItemImage::create(file, file, this, menu_selector(SettingView::inviteGo));
    invite->setPosition(ccp(Winsize.width / 2  , Winsize.height / 2 -180 ));
    
    
    
    
    on->setVisible(!bgstate);
    off->setVisible(bgstate);
    on_effect->setVisible(!effectstate);
    off_effect->setVisible(effectstate);
    
    CCMenu* menu = CCMenu::create(on,off,on_effect,off_effect,back,invite, NULL);
    menu->setPosition(CCPointZero);
    menu->setScale(g_fScaleX_);
    addChild(menu,6);
    
    
    
    
    //    CCLabelTTF* label = CCLabelTTF::create("SETTING", "CARTOON_REGULAR", 50);
    //    label->setPosition(ccp(Winsize.width / 2 , Winsize.height-200*g_fScaleY_));
    //    addChild(label,6);
    return true;
    
}
void SettingView:: setSuperScene(int number){
    superType = number;
}
void SettingView::setBackground(CCObject *pSender){
    
    bgstate = app->getBgSound();
    bgstate = !bgstate;
    app->setBgSound(bgstate);
    on->setVisible(!bgstate);
    off->setVisible(bgstate);
}
void SettingView::setEffect(CCObject *pSender){
    
    effectstate = app->geteffectSound();
    effectstate = !effectstate;
    app->seteffectSound(effectstate);
    on_effect->setVisible(!effectstate);
    off_effect->setVisible(effectstate);
    
}
void SettingView::backGo(CCObject *pSender){
    
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f, Title::scene()));
}

void SettingView::inviteGo(CCObject *pSender){
   
//    HelloWorld* invite;
//    invite->trySendAnEmailInApp();
}

 

