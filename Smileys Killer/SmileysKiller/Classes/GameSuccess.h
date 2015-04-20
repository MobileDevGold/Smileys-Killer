//
//  GameSuccess.h
//  SmileysKiller
//
//  Created by Mikhail Berrya on 10/19/13.
//
//

#ifndef __GAMESUCCESS_SCENE_H__
#define __GAMESUCCES_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "AppSettings.h"
USING_NS_CC ;

class GameSuccess : public CCLayerColor
{
public:
    
    virtual bool init();
    static CCScene* scene();
    
    CCSize WinSize;
    
    void initMenu();
    void onNext(CCObject* pSender);
    void onReply(CCObject* pSender);
    int m_nLevel;
    
    AppSettings* appSettigns;
    
    CCLabelTTF* m_lTitleLabel;
    CREATE_FUNC(GameSuccess);
};

#endif // __GAMESUCCESS_SCENE_H__
