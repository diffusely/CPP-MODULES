#include "Ice.h"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Ice object created!\n";
}

Ice::Ice(const Ice& copy)
	: AMateria(copy)
{
	std::cout << "Ice object copied!\n";
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Ice assignment operator called!\n";
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice object destroyed!\n";
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
