#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

void testDeepCopy()
{
    std::cout << "\n>>> RUNNING DEEPCOPY TESTS\n" << std::endl;

    std::cout << "--- Dog's behavior ---" << std::endl;
    Dog dogA;
    Dog dogB;

    dogA.getBrain()->setIdea("DogA idea", 0);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "DogA idea: " << dogA.getBrain()->getIdea(0) << std::endl;
    std::cout << "DogB idea: " << dogB.getBrain()->getIdea(0) << std::endl;

    dogB = dogA;

    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "DogA idea: " << dogA.getBrain()->getIdea(0) << std::endl;
    std::cout << "DogB idea: " << dogB.getBrain()->getIdea(0) << std::endl;

    dogB.getBrain()->setIdea("DogB new idea", 0);

    std::cout << "\nAfter modifying DogB:" << std::endl;
    std::cout << "DogA idea: " << dogA.getBrain()->getIdea(0) << std::endl;
    std::cout << "DogB idea: " << dogB.getBrain()->getIdea(0) << std::endl;


    std::cout << "\n--- Cat's behavior ---" << std::endl;
    Cat catA;
    Cat catB;

    catA.getBrain()->setIdea("CatA idea", 0);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "CatA idea: " << catA.getBrain()->getIdea(0) << std::endl;
    std::cout << "CatB idea: " << catB.getBrain()->getIdea(0) << std::endl;

    catB = catA;

    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "CatA idea: " << catA.getBrain()->getIdea(0) << std::endl;
    std::cout << "CatB idea: " << catB.getBrain()->getIdea(0) << std::endl;

    catB.getBrain()->setIdea("CatB new idea", 0);

    std::cout << "\nAfter modifying CatB:" << std::endl;
    std::cout << "CatA idea: " << catA.getBrain()->getIdea(0) << std::endl;
    std::cout << "CatB idea: " << catB.getBrain()->getIdea(0) << std::endl;
}

int main()
{
    std::cout << "Creating Animal array..." << std::endl;

    Animal* animals[4];

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\nDeleting Animal array..." << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\nTesting polymorphism..." << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog;
    delete cat;

    testDeepCopy();

    return 0;
}