#ifndef __STARTSCENE_H__
#define __STARTSCENE_H__

#include "cocos2d.h"
#include <string>

/********************************************************************

	created:	2013/07/30 23:11
	filename: 	D:\work\MonsterMaker\MonsterMaker\Classes\UI\JoinScene.h
	file path:	D:\work\MonsterMaker\MonsterMaker\Classes\UI
	author:		Ryu
	
	purpose:	새로운 게임 시작 씬
	- 사용자 이름 받기
	A 생일 받기
	A Player 객체 생성하기

	B 이름 검사하기

	C 요정 나와서 대화상자로 받기
	C Keyboard Notification Layer 로 바꾸기
*********************************************************************/

namespace MonsterMaker{ namespace Scenes{ namespace Start {
	class StartLayer : public cocos2d::Layer
	{
	public:
		virtual bool init();
		CREATE_FUNC(StartLayer);
	private:
		std::string m_sName;
		int m_iMonth, m_iDay;
	
		void menuCloseCallback(cocos2d::Object* pSender);
		void menuConfirmCallback(cocos2d::Object* pSender);	// 이름 입력 완료 콜백
	};
	
	class StartScene : public cocos2d::Scene{
	public:
		StartScene(){};
		~StartScene(){};
		bool init();
	};

	CREATE_FUNC(StartScene);

}}}

#endif // !__MAINSCENE_H__