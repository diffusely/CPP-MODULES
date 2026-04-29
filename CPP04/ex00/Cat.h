#pragma once

#include "Animal.h"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& copy);
	~Cat();

	Cat& operator=(const Cat& other);
	void makeSound() const;
};