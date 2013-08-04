#include "MainScene.h"
#include "StartScene.h"
#include "Resources/Resource.h"
#include "Util/Util.h"

USING_NS_CC;

namespace MonsterMaker { namespace Scenes{ namespace Main{

bool MainLayer::init()
{
	bool bRet = false;
	do{
		Util::origin = Director::getInstance()->getVisibleOrigin();
		Util::size = Director::getInstance()->getVisibleSize();

	//************************************************************************/
	//* Super Init First
	//************************************************************************/
	CC_BREAK_IF(! Layer::init());
	
	CCLOG("Main Scene Initialize");
	Size winSize = Director::getInstance()->getWinSize();
	


	/*************************************************************************/
	//* 메뉴 구성하기
	//************************************************************************/
	CCLOG("Menu initialize");

	// 레이블 생성
	LabelTTF *pNewGameLabel = LabelTTF::create("New Game",NFONT::MENU_FONT1,FONT_SIZE(30));
	CC_BREAK_IF(!pNewGameLabel);
	LabelTTF *pLoadGameLabel = LabelTTF::create("Load Game",NFONT::MENU_FONT1,FONT_SIZE(30));
	CC_BREAK_IF(!pLoadGameLabel);
	
	// 메뉴 아이템 생성
	MenuItemLabel *pNewGameItem = MenuItemLabel::create(pNewGameLabel, CC_CALLBACK_1(MainLayer::menuNewCallback, this));
	CC_BREAK_IF(!pNewGameItem);
	MenuItemLabel *pLoadGameItem = MenuItemLabel::create(pLoadGameLabel,CC_CALLBACK_1(MainLayer::menuLoadCallback,this));
	CC_BREAK_IF(!pLoadGameItem);

	// 메뉴 생성
	Menu *pMenu = Menu::create(pNewGameItem,pLoadGameItem,NULL);
	pMenu->alignItemsVerticallyWithPadding(10.0f); // 여백지정
	pMenu->setPosition(POS(winSize.width/2,winSize.height/2)); // 메뉴 위치 화면 가운데 지정 
	CC_BREAK_IF(!pMenu);
	this->addChild(pMenu,1); // 레이어에 메뉴 추가
	
	bRet = true;
	} while (0);
	
	return bRet;
}



void MainLayer::menuNewCallback( Object* pSender )
{
	CCLOG("New Game Callback");
	auto *pScene = Start::create();
	Director::getInstance()->replaceScene(pScene);
}

void MainLayer::menuLoadCallback( Object* pSender )
{
	CCLOG("Load Game Callback");
	/*DATA::loadGame();
	CCScene *pScene = Games::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);*/
	// TOOD: 데이터형 불러오기

}



bool MainScene::init()
{
	if( Scene::init() )
	{
		auto *pLayer = MainLayer::create();
		this->addChild(pLayer);

		return true;
	}
	else
	{
		return false;
	}
}

}}}