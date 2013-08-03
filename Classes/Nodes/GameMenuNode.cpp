#include "GameMenuNode.h"
#include "Resources/Resource.h"
#include "GameScene.h"
USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Games{

bool GameMenuNode::init()
{
	bool bRet = false;
	do{
		CCLOG("# Game Menu Layer Initialize Start #");
		/************************************************************************/
		/* Super Init First
		/************************************************************************/

		CC_BREAK_IF(!CCNode::init());
		

		/************************************************************************/
		/* 레이어 크기 지정                                                                    
		/************************************************************************/

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCSize layerSize = CCSizeMake(winSize.width,100);
		this->setContentSize(layerSize);



		/************************************************************************/
		/* 버튼                                                                    
		/************************************************************************/
		CCMenuItemImage *item1 = CCMenuItemImage::create(ICON::Friend,	ICON::Friend_s	);		// 친구목록
		CCMenuItemImage *item2 = CCMenuItemImage::create(ICON::Train,	ICON::Train_s	);		// 수행
		CCMenuItemImage *item3 = CCMenuItemImage::create(ICON::Arena,	ICON::Arena_s	);		// 투기장
		CCMenuItemImage *item4 = CCMenuItemImage::create(ICON::Storage, ICON::Storage_s	);			// 창고
		CCMenuItemImage *item5 = CCMenuItemImage::create(ICON::Castle,	ICON::Castle_s,	this, menu_selector(GameScene::menuSceneTransitionCallback));		// 외출

		float itemWidth	= item1->getContentSize().width;
		float itemHeight= item1->getContentSize().height;
		int iRows = 5;

		CCMenu *pMenu = CCMenu::create(item1,item2,item3,item4,item5,NULL);
		pMenu->alignItemsHorizontallyWithPadding((layerSize.width-itemWidth*5)/iRows);
		pMenu->setPosition(layerSize.width/2,itemHeight+5);
		CC_BREAK_IF(!pMenu);
		this->addChild(pMenu,1);

		/************************************************************************/
		/* 메뉴 텍스트                                                                    
		/************************************************************************/
		CCLabelTTF *text1  = CCLabelTTF::create(UITEXT::Friend,	FONT::MENU_FONT1,	FONT_SIZE(20));
		CCLabelTTF *text2  = CCLabelTTF::create(UITEXT::Train,	FONT::MENU_FONT1,	FONT_SIZE(20));
		CCLabelTTF *text3  = CCLabelTTF::create(UITEXT::Arena,	FONT::MENU_FONT1,	FONT_SIZE(20));
		CCLabelTTF *text4  = CCLabelTTF::create(UITEXT::Storage,	FONT::MENU_FONT1,	FONT_SIZE(20));
		CCLabelTTF *text5  = CCLabelTTF::create(UITEXT::Castle,	FONT::MENU_FONT1,	FONT_SIZE(20));

		

		text1->setPosition(ccp(32,-15));
		text2->setPosition(ccp(32,-15));
		text3->setPosition(ccp(32,-15));
		text4->setPosition(ccp(32,-15));
		text5->setPosition(ccp(32,-15));
		
		CC_BREAK_IF(!text1);
		CC_BREAK_IF(!text2);
		CC_BREAK_IF(!text3);
		CC_BREAK_IF(!text4);
		CC_BREAK_IF(!text5);

		item1->addChild(text1,1);
		item2->addChild(text2,1);
		item3->addChild(text3,1);
		item4->addChild(text4,1);
		item5->addChild(text5,1);

	
		CCLOG("# Game Menu Layer Initialize Complete #");
		bRet = true;

	} while(0);

		return bRet;
}

}}}