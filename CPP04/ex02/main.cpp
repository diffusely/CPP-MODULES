#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>

void testSubject()
{
    AAnimal* animals[4];

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n>>> RUNNING SUBJECT TESTS\n" << std::endl;

    for (int k = 0; k < 4; k++)
    {
        if (k < 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "Filling done. Deleting every Animal..." << std::endl;

    for (int k = 0; k < 4; k++)
        delete animals[k];
}

void testDeepCopy()
{
	Dog	dogA;
	Dog	dogB;
	Cat	catA;
	Cat	catB;

	std::cout << "\n>>> RUNNING DEEPCOPY TESTS\n" << std::endl;
	std::cout << "--- Dog's behavior ---" << std::endl;
	dogA.getBrain()->setIdea("DogA idea", 0);
	std::cout << "Before assignment:" << std::endl;
	std::cout << "DogA: " << dogA.getBrain()->getIdea(0) << std::endl;
	std::cout << "DogB: " << dogB.getBrain()->getIdea(0) << std::endl;
	dogB = dogA;
	std::cout << "\nAfter assignment:" << std::endl;
	std::cout << "DogA: " << dogA.getBrain()->getIdea(0) << std::endl;
	std::cout << "DogB: " << dogB.getBrain()->getIdea(0) << std::endl;
	dogB.getBrain()->setIdea("DogB new idea", 0);
	std::cout << "\nAfter modifying DogB:" << std::endl;
	std::cout << "DogA: " << dogA.getBrain()->getIdea(0) << std::endl;
	std::cout << "DogB: " << dogB.getBrain()->getIdea(0) << std::endl;
	std::cout << "\n--- Cat's behavior ---" << std::endl;
	catA.getBrain()->setIdea("CatA idea", 0);
	std::cout << "Before assignment:" << std::endl;
	std::cout << "CatA: " << catA.getBrain()->getIdea(0) << std::endl;
	std::cout << "CatB: " << catB.getBrain()->getIdea(0) << std::endl;
	catB = catA;
	std::cout << "\nAfter assignment:" << std::endl;
	std::cout << "CatA: " << catA.getBrain()->getIdea(0) << std::endl;
	std::cout << "CatB: " << catB.getBrain()->getIdea(0) << std::endl;
	catB.getBrain()->setIdea("CatB new idea", 0);
	std::cout << "\nAfter modifying CatB:" << std::endl;
	std::cout << "CatA: " << catA.getBrain()->getIdea(0) << std::endl;
	std::cout << "CatB: " << catB.getBrain()->getIdea(0) << std::endl;
}

int main()
{
    testSubject();
    testDeepCopy();

    std::cout << "\nAll tests completed." << std::endl;
    return (0);
}