#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << "Animal type: " << j->getType() << "\n";
	j->makeSound();

	std::cout << "Animal type: " << i->getType() << "\n";
	i->makeSound();
	std::cout << "Animal type: " << meta->getType() << "\n";
	meta->makeSound();

	std::cout << "Animal type: " << wrong->getType() << "\n";
	wrong->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	return (0);
}