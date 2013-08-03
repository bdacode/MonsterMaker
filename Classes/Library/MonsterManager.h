#ifndef __MONSTER_H__
#define  __MONSTER_HH

#include "Monster.h"
#include "Serializer.h"
#include <map>
#include "json.h"

namespace GameLib{	namespace Monsters{
	class MonsterManager : public Serializer::IJsonSerializable {
	public:

		// 인스턴스
		static MonsterManager *getInstance();
		void release();

		// 몬스터 리스트
		vector<string> getMonsterKeys();

		// 몬스터
		void addMonster(Monster _monster);;
		Monster* getMonster(string _name);;
		bool containMonster(string _name);

		// 버전
		double getVersion(); 
		void setVersion(double _version);

		// 시리얼라이제이션
		virtual void Serialize( Json::Value& root );
		virtual void Deserialize( Json::Value& root );

	private:
		MonsterManager();
		~MonsterManager();

		map<string, Monster> m_Monsters;
		static MonsterManager *m_sMonsterManager;
		float m_dVersion;


	};
}}
#endif