#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC ;
class GameOver : public CCLayerColor
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
  
    CCSize WinSize;
    
    void initMenu();
    void onNext(CCObject* pSender);
    void onReply(CCObject* pSender);
    
    CCLabelTTF* m_lTitleLabel;
    CREATE_FUNC(GameOver);
};

#endif // __GAMEOVER_SCENE_H__
