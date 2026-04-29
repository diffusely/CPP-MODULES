#pragma once

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& copy);
	~Cat();

	Cat& operator=(const Cat& other);
	Brain* getBrain() const;
	void makeSound() const;

private:
	Brain* brain;
};

