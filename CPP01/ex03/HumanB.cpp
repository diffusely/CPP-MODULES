#include "HumanB.h"

HumanB::HumanB(const std::string& name)
	: _name(name)
	, _weapon(NULL)
{}

HumanB::~HumanB()
{}

void HumanB::attack(void) const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
	else
		std::cout << _name << " has no weapon to attack.\n";

}

void HumanB::setWeapon(Weapon& type)
{
	_weapon = &type;
}
