#include "Cat.h"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat's default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called\n";
}

Cat::Cat(const Cat& copy)
	: Animal(copy)
{
	std::cout << "Cat's copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat's copy assignment operator called\n";
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meowww\n";
}
