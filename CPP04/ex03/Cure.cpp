#include "Cure.h"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Cure object created!\n";
}

Cure::Cure(const Cure& copy): AMateria(copy)
{
	std::cout << "Cure object copied!\n";
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Cure copy assignment operator called!\n";
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure object destroyed!\n";
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
