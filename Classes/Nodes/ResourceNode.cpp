#include "ResourceNode.h"
#include "Resources/Resource.h"

USING_NS_CC;

namespace MonsterMaker{ namespace Scenes { namespace Games{

	bool ReesourceNode::init()
	{			
		bool bRet = false;

		do{
			CCLOG("# Resource Node Initialize Start #");
			/************************************************************************/
			/* Super Init First
			/************************************************************************/

			CC_BREAK_IF(!CCNode::init());	

			/************************************************************************/
			/* 레이어 크기 지정                                                                    
			/************************************************************************/

			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			CCSize layerSize = CCSizeMake(winSize.width,80.0f);
			this->setContentSize(layerSize);

			/************************************************************************/
			/* 아이콘 스프라이트                                                                    
			/************************************************************************/

			// 빈하트 아이콘
			CCSprite *pHeartBlankSpr[6];
			for(int i = 0; i < 6 ; i ++) {
				pHeartBlankSpr[i] = CCSprite::create(SPRITE::HeartBlank);
				pHeartBlankSpr[i]->setPosition(ccp(layerSize.width*0.55+(pHeartBlankSpr[i]->getContentSize().width/2+20.0f)*i,layerSize.height/2));
				CC_BREAK_IF(!pHeartBlankSpr[i]);
				this->addChild(pHeartBlankSpr[i],1);
			}

			// 꽉찬 하트 아이콘
			for(int i = 0; i < 6 ; i ++) {
				m_pHeartSpr[i] = CCSprite::create(SPRITE::Heart);
				m_pHeartSpr[i]->setPosition(ccp(layerSize.width*0.55+(m_pHeartSpr[i]->getContentSize().width/2+20.0f)*i,layerSize.height/2));
				m_pHeartSpr[i]->setVisible(false);
				CC_BREAK_IF(!m_pHeartSpr);
				this->addChild(m_pHeartSpr[i],2);
			}


			// 수정
			CCSprite *pCrystalSpr = CCSprite::create(SPRITE::Crystal);
			pCrystalSpr->setPosition(ccp(layerSize.width/2.5, layerSize.height/2));
			CC_BREAK_IF(!pCrystalSpr);
			this->addChild(pCrystalSpr,1);

			// 골드
			CCSprite *pGoldSpr = CCSprite::create(SPRITE::Gold);
			pGoldSpr->setPosition(ccp(layerSize.width*0.9, 0));
			CC_BREAK_IF(!pGoldSpr);
			this->addChild(pGoldSpr,1);


			/************************************************************************/
			/* 레이블                                                                    
			/************************************************************************/

			// 수정 숫자
			CCLabelTTF *pCrystalLabel = CCLabelTTF::create("0","맑은 고딕",20);
			pCrystalLabel->setPosition(ccp(layerSize.width/3+40.0f, layerSize.height/2));
			//this->addChild(pCrystalLabel,1);


			// 골드 숫자
			CCLabelTTF *pGoldLabel = CCLabelTTF::create("100","맑은 고딕",20,CCSizeMake(200,30),kCCTextAlignmentRight);
			pGoldLabel->setAnchorPoint(ccp(1.0,0.5));
			pGoldLabel->setPosition(ccp(pGoldSpr->getPositionX()-30,pGoldSpr->getPositionY()));
			this->addChild(pGoldLabel,1);


			CCLOG("# Resource Node Initialize Complete #");
			bRet = true;

		} while(0);

		return bRet;

	}

	void ReesourceNode::onExitTransitionDidStart()
	{
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCAction *pAction = CCMoveTo::create(0.1f,ccp(0,winSize.height));
		this->runAction(pAction);


	}

	void ReesourceNode::onEnterTransitionDidFinish()
	{
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCAction *pAction = CCMoveTo::create(0.1f,ccp(0,winSize.height-this->getContentSize().height));
		this->runAction(pAction);
	}


}}}







