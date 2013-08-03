#ifndef __MONSTER_H__
#define  __MONSTER_HH

#include "Monster.h"
#include "Serializer.h"
#include <map>
#include "json.h"

namespace GameLib{	namespace Monsters{
	class MonsterManager : public Serializer::IJsonSerializable {
	public:

		// �ν��Ͻ�
		static MonsterManager *getInstance();
		void release();

		// ���� ����Ʈ
		vector<string> getMonsterKeys();

		// ����
		void addMonster(Monster _monster);;
		Monster* getMonster(string _name);;
		bool containMonster(string _name);

		// ����
		double getVersion(); 
		void setVersion(double _version);

		// �ø���������̼�
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