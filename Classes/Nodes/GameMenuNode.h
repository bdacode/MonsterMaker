#ifndef __GAMEMENUNODE_H__
#define __GAMEMENUNODE_H__


#include "cocos2d.h"
#include "AppMacros.h"

/********************************************************************

	created:	2013/07/28 16:37
	filename: 	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\UI\GameMenu.h
	file path:	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\UI
	author:		Ryu
	
	purpose:	GameScene's Menu
	
	- 게임 메인 메뉴 (화면 아래)
	- 친구목록, 수행, 투기장, 창고, 외출

*********************************************************************/

namespace MonsterMaker{ namespace Scenes { namespace Games{

	class GameMenuNode : public cocos2d::CCNode
	{
	public:
	
		CREATE_FUNC(GameMenuNode);
		virtual bool init();


	private:

	};

}}}




#endif