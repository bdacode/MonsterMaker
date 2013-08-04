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
	//* �޴� �����ϱ�
	//************************************************************************/
	CCLOG("Menu initialize");

	// ���̺� ����
	LabelTTF *pNewGameLabel = LabelTTF::create("New Game",NFONT::MENU_FONT1,FONT_SIZE(30));
	CC_BREAK_IF(!pNewGameLabel);
	LabelTTF *pLoadGameLabel = LabelTTF::create("Load Game",NFONT::MENU_FONT1,FONT_SIZE(30));
	CC_BREAK_IF(!pLoadGameLabel);
	
	// �޴� ������ ����
	MenuItemLabel *pNewGameItem = MenuItemLabel::create(pNewGameLabel, CC_CALLBACK_1(MainLayer::menuNewCallback, this));
	CC_BREAK_IF(!pNewGameItem);
	MenuItemLabel *pLoadGameItem = MenuItemLabel::create(pLoadGameLabel,CC_CALLBACK_1(MainLayer::menuLoadCallback,this));
	CC_BREAK_IF(!pLoadGameItem);

	// �޴� ����
	Menu *pMenu = Menu::create(pNewGameItem,pLoadGameItem,NULL);
	pMenu->alignItemsVerticallyWithPadding(10.0f); // ��������
	pMenu->setPosition(POS(winSize.width/2,winSize.height/2)); // �޴� ��ġ ȭ�� ��� ���� 
	CC_BREAK_IF(!pMenu);
	this->addChild(pMenu,1); // ���̾ �޴� �߰�
	
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
	// TOOD: �������� �ҷ�����

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