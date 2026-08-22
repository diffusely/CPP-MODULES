#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>

int	main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::vector<int>::iterator it = easyfind(vec, 20);
	std::cout << "found in vector: " << *it << std::endl;

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::list<int>::iterator lit = easyfind(lst, 2);
	std::cout << "found in list: " << *lit << std::endl;

	try
	{
		easyfind(vec, 999);
	}
	catch (std::exception& e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	return (0);
}
