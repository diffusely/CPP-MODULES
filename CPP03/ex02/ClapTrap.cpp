#include "ClapTrap.h"

ClapTrap::ClapTrap()
	: _name("Default")
	, _hitPoint(10)
	, _energy(10)
	, _damage(0)
{
	std::cout << _name << " created.\n";
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name)
	, _hitPoint(10)
	, _energy(10)
	, _damage(0)
{
	std::cout << _name << " created.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " destroyed.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoint = other._hitPoint;
	_energy = other._energy;
	_damage = other._damage;
	std::cout << _name << " copied.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment called.\n";
	if (this != &other) {
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energy = other._energy;
		_damage = other._damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy && _hitPoint > 0) {
		_energy--;
		std::cout << _name << " attacted " << target << " causing " << _damage << " points of damage!\n";
	}
	if (_hitPoint <= 0)
		std::cout << _name << " is dead!\n";
	else if (!_energy)
		std::cout << _name << " is out of energy points!\n";
}

void	ClapTrap::takeDamage(int amount)
{
	if (amount < 0) {
		std::cout << "Wrong amount\n";
		return ;
	}
	if (_hitPoint > 0) {
		std::cout << _name << " took " << amount << " points of damage!\n";
		_hitPoint -= amount;
	}
	else
		std::cout << _name << " is already dead!\n";
	if (_hitPoint < 0)
		_hitPoint = 0;
}

void	ClapTrap::beRepaired(int amount)
{
	if (amount < 0) {
		std::cout << "Wrong amount\n";
		return ;
	}
	if (_hitPoint > 0 && _energy) {
		std::cout << _name << " has been repaired " << amount << " points of damage!\n";
		--_energy;
		_hitPoint += amount;
	}
	if (_hitPoint <= 0)
		std::cout << "Cannot repair: " << _name << " is already dead.\n";
	else if (!_energy)
		std::cout << _name << " is out of energy points!\n";
}