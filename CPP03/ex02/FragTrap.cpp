#include "FragTrap.h"

FragTrap::FragTrap(void)
	: ClapTrap("Default ClapTrap")
{
	_hitPoint = 100;
	_energy = 100;
	_damage = 30;
	std::cout << _name << " created.\n";
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoint = 100;
    _energy = 100;
    _damage = 30;
    std::cout << _name << " created.\n";
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << _name << " copied.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Copy assignment operator for FragTrap called.\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << _name << " destroyed.\n";
}

void FragTrap::highFivesGuys()
{
    if (_hitPoint <= 0)
        std::cout << "Cannot high five because " << _name << " is dead.\n";
    else if (_energy <= 0)
        std::cout << _name << " is out of energy points, cannot high five.\n";
    else
        std::cout << _name << " gives a high five!\n";
}
