#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap()
    : ClapTrap("Default ScavTrap")
{
    _hitPoint = 100;
    _energy = 50;
    _damage = 20;
    std::cout << _name << " created.\n";
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoint = 100;
    _energy = 50;
    _damage = 20;
    std::cout << _name << " created.\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << _name << " copied.\n";
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << _name << " destroyed.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Copy assignment operator for ScavTrap called.\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::guardGate()
{
    if (_hitPoint <= 0)
        std::cout << "Cannot switch Gate keeper mode: " << _name << " is dead.\n";
    else
        std::cout << _name << " switched to Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoint <= 0) {
        std::cout << _name << " is dead!\n";
        return;
    }
    if (_energy <= 0) {
        std::cout << _name << " is out of energy points!\n";
        return;
    }

    _energy--;
    std::cout << _name << " attacked " << target
              << " causing " << _damage << " points of damage!\n";
}