#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"

class Title: public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    void initMenu();
    // a selector callback
    void menuPlay(CCObject* pSender);
    void menuSettings(CCObject* pSender);
    void menuLeaderBoard(CCObject* pSender);

    
    // implement the "static node()" method manually
    CREATE_FUNC(Title);
protected:
    cocos2d::CCSize  VisibleSize;

};

#endif // __TITLE_SCENE_H__
