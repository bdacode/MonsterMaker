#ifndef __RESOURCENODE_H__
#define __RESOURCENODE_H__

#include "cocos2d.h"

/********************************************************************

	created:	2013/07/29 11:45
	filename: 	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\UI\Info.h
	file path:	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\UI
	author:		Ryu
	
	purpose:	정보 표시 레이어
	- 하트 현황
	- 하트 구입 버튼
	- 골드 현황
*********************************************************************/

namespace MonsterMaker{ namespace Scenes { namespace Games{

	class ReesourceNode : public cocos2d::CCNode
	{
	public:
	
		CREATE_FUNC(ReesourceNode);
		virtual bool init();
		
	private:
		cocos2d::CCSprite *m_pHeartSpr[6];
		void onExitTransitionDidStart();
		void onEnterTransitionDidFinish();

	};
}}}




#endif