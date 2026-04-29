#include "AAnimal.h"

AAnimal::AAnimal()
	: _type("Unknown")
{
	std::cout << "AAnimal's default constructor called with type " << _type << "\n";
}

AAnimal::AAnimal(std::string type)
	: _type(type)
{
	std::cout << "AAnimal's default constructor called with type " << _type << "\n";
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal's destructor called with type " << _type << "\n";
}

AAnimal::AAnimal(const AAnimal& copy)
{
	_type = copy._type;
	std::cout << "AAnimal's copy constructor called with type " << _type << "\n";
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "Animal's copy assignment operator called with type " << _type << "\n";
	return (*this);
}

const std::string&	AAnimal::getType() const
{
	return (_type);
} 

void	AAnimal::setType(std::string str)
{
	_type = str;
}

void	AAnimal::makeSound() const
{
	std::cout << "Undefined sound\n";
}
