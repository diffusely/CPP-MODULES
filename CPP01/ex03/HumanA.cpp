#include "HumanA.h"

HumanA::HumanA(const std::string& name, Weapon& type)
	: _name(name)
	, _weapon(type)
{}

HumanA::~HumanA()
{}

void HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}

void HumanA::setWeapon(const Weapon& type)
{
	_weapon = type;
}
