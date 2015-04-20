//
//  SettingScene.h
//  SmileysKiller
//
//  Created by TaiMing on 10/15/13.
//
//

#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__
#include "cocos2d.h"
#include "AppSettings.h" 

using namespace cocos2d;
class SettingView : public cocos2d:: CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    static cocos2d::CCScene* scene();
    static cocos2d::CCLayer* layer();
    static SettingView* setting();
    virtual bool init();
    AppSettings* app;
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    bool bgstate;
    bool effectstate;
    int superType;
    CCSize Winsize;
    CCMenuItemImage* on;
    CCMenuItemImage* off;
    CCMenuItemImage* on_effect;
    CCMenuItemImage* off_effect;
    CCMenuItemImage* invite;
    CCMenuItemImage* back;
    void setBackground(CCObject* pSender);
    void setEffect(CCObject* pSender);
    void inviteGo(CCObject* pSender);
    void backGo(CCObject*pSender);
    void initMenu(int type);
    void setSuperScene(int number);
    // a selector callback
    
    
    
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(SettingView);
    
};

#endif //__SETTING_SCENE_H__
