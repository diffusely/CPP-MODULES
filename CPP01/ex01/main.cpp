#include "Zombie.h"

int main()
{
	const int SIZE = 10;

	Zombie* zombie = zombieHorde(SIZE, "Horde");

	if (!zombie)
		return 0;

	for (int i = 0; i < SIZE; i++)
		zombie->announce();

	delete[] zombie;
	return 0;
}