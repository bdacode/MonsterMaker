#ifndef __DATEMANAGER_H__
#define __DATEMANAGER_H__

#include <time.h>

#include "json.h"

/********************************************************************

	created:	2013/07/24 12:19
	filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\GameLib\DateManager.h
	file path:	D:\gitdev\projectmarble\MonsterMaker\Classes\GameLib
	author:		Ryu
	
	purpose:	시간 관리 클래스
	-현재 시간 보관

*********************************************************************/


namespace GameLib { namespace Dates {
class DateManager{

public:


private:
	time_t m_tGameStartDate;
	
	static DateManager *m_sDateManager;

	DateManager();
	~DateManager();
};

}}

#endif // !__DATEMANAGER_H__