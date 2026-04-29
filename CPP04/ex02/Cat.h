#pragma once

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal
{
public:
	Cat(void);
	Cat(const Cat& copy);
	~Cat();

	Cat& operator=(const Cat& other);
	Brain* getBrain() const;
	void makeSound() const;

private:
	Brain*	brain;
};
