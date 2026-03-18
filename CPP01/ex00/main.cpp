#include "Zombie.h"

int main()
{
	Zombie* zombie = new Zombie("test");
	zombie->announce();

	randomChump("test2");

	{
		Zombie* nZombie = newZombie("test1");
		nZombie->announce();
		delete nZombie;
	}

	zombie->setName("newName");
	zombie->announce();
	delete zombie;
	return 0;
}