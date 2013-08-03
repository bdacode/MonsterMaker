#ifndef __CALENDERNODE_H__
#define __CALENDERNODE_H__

#include "cocos2d.h"

/********************************************************************

	created:	2013/07/27 21:00
	filename: 	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes\CalenderLayer.h
	file path:	D:\work\cocos2d-x-2.1.4\MonsterMaker\Classes
	author:		Ryu
	
	purpose:	�޷� ���̾�
	�޷�ǥ��
	��¥ ������Ʈ
	���� �������� ���� ǥ��
*********************************************************************/

namespace MonsterMaker{ namespace Scenes { namespace Games{

	class CalenderNode : public cocos2d::CCNode
	{
	public:
	
		CREATE_FUNC(CalenderNode);
		virtual bool init();


	private:
		cocos2d::CCLabelTTF *pYearLabel, *pMonthLabel, *pDayLabel, *pWeekLabel;

	};

}}}




#endif