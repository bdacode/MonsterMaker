#include "StartScene.h"
#include "Resources/Resource.h"
#include "Components/Player.h"	
#include "Game/GameScene.h"		// Next Scene
#include "Util/Util.h"		// Util

USING_NS_CC;

namespace MonsterMaker { namespace Scenes{ namespace Starts{

/************************************************************************/
/* Start Layer                                                                    
/************************************************************************/

bool StartLayer::init()
{
	bool bRet = false;
	do{
	// Super Init & Content Size Init
	CC_BREAK_IF(!Layer::init());
	CCLOG("Start Scene Initialize");

	Size layerSize = CCDirector::getInstance()->getVisibleSize();
	this->setContentSize(layerSize);


	
	// Scene Title Text                                                                    
	LabelTTF *title = LabelTTF::create("Join Scene",NFONT::MENU_FONT1,FONT_SIZE(20));
	title->setPosition(POS(layerSize.width/2,layerSize.height-title->getContentSize().height/2));
	
	CC_BREAK_IF(!title);
	this->addChild(title,1);
	
	
	// "이름을 입력해주세요" 레이블
	LabelTTF *pText1 = LabelTTF::create(NUITEXT::InputName,NFONT::MENU_FONT1,FONT_SIZE(20));	//Text : Input Your name
	pText1->setPosition(POS(layerSize.width/2,500));
	CC_BREAK_IF(!pText1);
	this->addChild(pText1,1);

	// 텍스트 입력하는 곳
	TextFieldTTF *textField = TextFieldTTF::textFieldWithPlaceHolder("Text Input !", Size(200, 25), Label::HAlignment::CENTER, NFONT::MENU_FONT1, 12);
	textField->setPosition(POS(layerSize.width/2,400));
	this->addChild(textField,1,100);
	textField->attachWithIME();


	// Button : Ok
	LabelTTF *pText_OK = LabelTTF::create(NUITEXT::Confirm,NFONT::MENU_FONT1,FONT_SIZE(20));
	MenuItem *pItem1 = MenuItemLabel::create(pText_OK,CC_CALLBACK_1(StartLayer::menuConfirmCallback,this));
	Menu *pMenu = Menu::create(pItem1,NULL);
	pMenu->setPosition(POS(layerSize.width/2,300));
	CC_BREAK_IF(!pMenu);
	this->addChild(pMenu,1);


	/************************************************************************/
	/* 종료 버튼                                                                    
	/************************************************************************/
	MenuItemImage *closeItem = MenuItemImage::create("CloseNormal.png",	"CloseSelected.png",CC_CALLBACK_1(StartLayer::menuCloseCallback, this));
	closeItem->setPosition(POS(layerSize.width - closeItem->getContentSize().width/2 ,closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	Menu* menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);


	 
	/************************************************************************/
	/* 터치, 키패드 가능                                                                    
	/************************************************************************/

	this->setTouchEnabled(true);
	this->setKeypadEnabled(true);

	bRet = true;
	} while (0);
	
	return bRet;
}

void StartLayer::menuCloseCallback( cocos2d::Object* pSender ) // 종료
{
	cocos2d::Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void StartLayer::menuConfirmCallback( cocos2d::Object* pSender ) // 이름 입력 완료
{
	TextFieldTTF *pTarget = (TextFieldTTF*)this->getChildByTag(100);
	
	// Player 객체 생성 및 값 대입
	NPLAYER::gInstance = new NPLAYER::Player(pTarget->getString(),0);
	
	auto *pNExtScene = Scenes::Games::create();
	Director::getInstance()->replaceScene(pNExtScene);
}


/************************************************************************/
/* Start Scene                                                                    
/************************************************************************/

bool StartScene::init()
{
	if( Scene::init() )
	{
		auto *pLayer = StartLayer::create();
		this->addChild(pLayer);

		return true;
	}
	else
	{
		return false;
	}
}



}}}