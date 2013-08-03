#ifndef __DATA_H__
#define __DATA_H__

/********************************************************************

	created:	2013/07/30 14:36
	filename: 	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\Components\DataManager.h
	file path:	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\Components
	author:		Ryu
	
	purpose:	데이터 매니저
	- 새로운 게임 시작
	- 게임 불러오기

*********************************************************************/

namespace MonsterMaker { namespace Components { namespace Datas{
	bool newGame();		// 새로운 게임 시작하기
	bool loadGame();	// 게임 불러오기
	
	
}}}

namespace DATA = MonsterMaker::Components::Datas;

#endif
