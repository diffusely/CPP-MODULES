#include "WrongCat.h"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat's default constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's destructor called\n";
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << "WrongCat's copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat's copy assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meoww\n";
}