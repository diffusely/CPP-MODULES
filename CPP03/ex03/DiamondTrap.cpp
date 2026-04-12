#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
{
	ClapTrap::_name = "default_clap_name";
	hitPoint = 100;
	energy = 50;
	damage = 30;
	std::cout << "DiamondTrap " << _name << " created.\n";
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoint = 100;
	_energy = 50;
	_damage = 30;
	std::cout << "DiamondTrap " << _name << " created.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	name = copy._name;
	std::cout << "DiamondTrap " << _name << " copied.\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Copy assignment operator for DiamondTrap called.\n";
	if (this != &other) {
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energy = other._energy;
		_damage = other._damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed.\n";
}

void	DiamondTrap::whoAmI()
{
	if (this->_hitPoint <= 0)
		std::cout << "Cannot run whoAmI because: DiamondTrap " << _name << " is already dead.\n";
	else {
		std::cout << "DiamondTrap name: " << _name << ".\n";
		std::cout << "ClapTrap name: " << ClapTrap::_name << ".\n";
	}
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}