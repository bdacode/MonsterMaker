#ifndef __DATE_H__
#define __DATE_H__

#include "Serializer.h"
#include <stdint.h>

/********************************************************************

	created:	2013/07/23 11:42
	filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\GameLib\Date.h
	file path:	D:\gitdev\projectmarble\MonsterMaker\Classes\GameLib
	author:		Ryu
	
	purpose:	날짜 클래스
*********************************************************************/
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))


namespace GameLib { namespace Dates {
	class Date : public Serializer::IJsonSerializable {
	
	public:
		Date ();
		Date (uint16_t _year, uint16_t _month, uint16_t _day);  // 생성자
		~Date();
	
		
		uint16_t getMonth();
		void setMonth(uint16_t _month);
		
		uint16_t getDay();
		void setDay(uint16_t _day);

		uint16_t getYear();
		void setYear(uint16_t _year);
	
		virtual void Serialize( Json::Value& root );
		virtual void Deserialize( Json::Value& root );

	private:
		uint16_t m_iMonth, m_iDay, m_iYear;

	};
}}

#endif