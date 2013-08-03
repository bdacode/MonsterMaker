#include "Serializer.h"
#include <string>

namespace MonsterMaker {namespace Library {  namespace Serial{

bool Serialize( IJsonSerializable* pObj, std::string& output )
{
	if (pObj == NULL)
		return false;

	CSJson::Value serializeRoot;
	pObj->Serialize(serializeRoot);

	CSJson::StyledWriter writer;
	output = writer.write( serializeRoot );

	return true;
}

bool Deserialize( IJsonSerializable* pObj, std::string& input )
{
	if (pObj == NULL)
		return false;

	CSJson::Value deserializeRoot;
	CSJson::Reader reader;

	if ( !reader.parse(input, deserializeRoot) )
		return false;

	pObj->Deserialize(deserializeRoot);

	return true;
}
}}}