#include "CalenderNode.h"
#include "Resources/Resource.h"

USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Games {


bool CalenderNode::init()
{
	
		bool bRet = false;
		do{

			/************************************************************************/
			/* Super Init First
			/************************************************************************/
			CC_BREAK_IF(! CCNode::init());
			CCLOG("# Calender Layer Initialize Start #");

			/************************************************************************/
			/* ���̾� ũ�� ����                                                                    
			/************************************************************************/
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			CCSize layerSize = CCSize(140.0f,80.0f);
			this->setContentSize(layerSize);
			
			/************************************************************************/
			/* ��� ����                                                                    
			/************************************************************************/

			CCSprite *pBackground = CCSprite::create(SPRITE::Calender);
			pBackground->setPosition(ccp(layerSize.width/2,layerSize.height/2));
			CC_BREAK_IF(!pBackground);
			this->addChild(pBackground,0);

			/************************************************************************/
			/* ��¥ ���̺�                                                                     
			/************************************************************************/

			// �ʱ�ȭ
			pYearLabel	= CCLabelTTF::create("100",		FONT::MENU_FONT1,	FONT_SIZE(20));
			pMonthLabel = CCLabelTTF::create("1",		FONT::MENU_FONT1,	FONT_SIZE(20));
			pDayLabel	= CCLabelTTF::create("1",		FONT::MENU_FONT1,	FONT_SIZE(20));
			pWeekLabel	= CCLabelTTF::create("������",	FONT::MENU_FONT1,	FONT_SIZE(20));

			// ��ġ����
			pYearLabel	->setPosition(ccp(layerSize.width/2,	layerSize.height-15));
			pMonthLabel	->setPosition(ccp(layerSize.width*0.2,	layerSize.height*0.5));
			pDayLabel	->setPosition(ccp(layerSize.width*0.2,	layerSize.height*0.2));
			pWeekLabel	->setPosition(ccp(layerSize.width*0.7,	layerSize.height*0.4));

			CC_BREAK_IF(!pYearLabel);
			CC_BREAK_IF(!pMonthLabel);
			CC_BREAK_IF(!pDayLabel);
			CC_BREAK_IF(!pWeekLabel);

			// ��� �߰�
			this->addChild(pYearLabel,1);
			this->addChild(pMonthLabel,1);
			this->addChild(pDayLabel,1);
			this->addChild(pWeekLabel,1);


			CCLOG("# Calender Layer Initialize Complete #");
			bRet = true;
		} while (0);

		return bRet;
}


}}}