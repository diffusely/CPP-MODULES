#include "Span.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(100);
	}
	catch (std::exception& e)
	{
		std::cout << "caught overflow: " << e.what() << std::endl;
	}

	Span empty(5);
	try
	{
		empty.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << "caught empty shortest: " << e.what() << std::endl;
	}
	try
	{
		empty.longestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << "caught empty longest: " << e.what() << std::endl;
	}

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Span big(10000);
	for (int i = 0; i < 10000; i++)
		big.addNumber(std::rand());

	std::cout << "big shortest: " << big.shortestSpan() << std::endl;
	std::cout << "big longest: " << big.longestSpan() << std::endl;

	return (0);
}
