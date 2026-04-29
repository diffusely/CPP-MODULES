#include "Cat.h"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat's default constructor called" << "\n";
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called" << "\n";
	delete brain;
}

Cat::Cat(const Cat& copy)
	: Animal(copy)
{
	std::cout << "Cat's copy constructor called" << "\n";
	brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat's copy assignment operator called" << "\n";
	if (this != &other) {
		_type = other._type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Brain* Cat::getBrain() const
{
	return (brain);
}

void Cat::makeSound() const
{
	std::cout << "Meoww\n";
}
