#pragma once

#include "Serializer.h"

#include <string>

/********************************************************************
	created:	2013/07/20 2:26
	filename: 	D:\gitdev\projectmarble\MonsterMaker\Classes\Library\MMMonster.h
	file path:	D:\gitdev\projectmarble\MonsterMaker\Classes\Library
	author:		Ryu

	purpose:	몬스터 클래스
*********************************************************************/

using namespace std;

namespace GameLib{ namespace Monsters{

	class Monster : public Serializer::IJsonSerializable {
	public:
		string getName();

		virtual void Serialize( Json::Value& root );
		virtual void Deserialize( Json::Value& root );

	private:
		string m_sName;
		int m_iDex;


	};
}
}