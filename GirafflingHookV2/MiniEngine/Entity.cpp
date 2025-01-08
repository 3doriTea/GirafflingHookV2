#include "Entity.h"
#include <typeinfo>

std::string Entity::ToString()
{
	const type_info& id = typeid(*this);
	return id.name();
}
