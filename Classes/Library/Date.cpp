#include "Date.h"
#include "json.h"
#include <sstream>
#include <string>


namespace GameLib { namespace Dates{

	Date::Date()
	{
		m_iMonth = m_iDay = m_iYear = 1;
	}

	Date::Date(uint16_t _year, uint16_t _month, uint16_t _day)
	{
		m_iMonth = max(1, _month);
		m_iMonth = min(m_iMonth,12);

		m_iDay = max(1,_day);
		m_iDay = min(_day,30);

		m_iYear = max(1, _year);
	}

	void Date::Serialize( Json::Value& root )
	{
		std::stringstream ss;
		ss << m_iYear << "/" << m_iMonth << "/" <<m_iDay;		// 연도/월/날짜
		root["GameDate"] = ss.str();

	}

	void Date::Deserialize( Json::Value& root )
	{
		std::string dateStr = root.get("GameDate","1/1/1").asString();
		std::stringstream ss(dateStr);
		char trim;
		ss >> m_iYear >> trim >> m_iMonth >> trim >> m_iDay;

	}

	Date::~Date()
	{
	
	}

	void Date::setMonth( uint16_t _month )
	{
		m_iMonth = _month;
	}

	uint16_t Date::getMonth()
	{
		return m_iMonth;
	}

	uint16_t Date::getDay()
	{
		return m_iDay;
	}

	void Date::setDay( uint16_t _day )
	{
		m_iDay  =_day;
	}

	void Date::setYear( uint16_t _year )
	{
		m_iYear = _year;
	}

	uint16_t Date::getYear()
	{
		return m_iYear;
	}


}}