#include "Weapon.h"

Weapon::Weapon(const std::string& name)
	: _name(name)
{}

Weapon::~Weapon()
{}

const std::string& Weapon::getType(void) const
{
	return _name;
}

void Weapon::setType(const std::string& str)
{
	_name = str;
}
