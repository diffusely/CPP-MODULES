#include "Bureaucrat.h"

int	main(void)
{
	std::cout << "GENERAL" << std::endl;
	{
		// Constructor
		Bureaucrat	a("Bob", 87);

		// Copy Constructor
		Bureaucrat	b(a);
		// ostream overload
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 1" << std::endl;
		try
		{
			// grade too low
			Bureaucrat	a("A", LOW_GRADE + 1);
			std::cout << a << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "TEST 2" << std::endl;
		try
		{
			// grade too high
			Bureaucrat	b("B", HIGH_GRADE - 1);
			std::cout << b << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "TEST 3" << std::endl;
		try
		{
			// Increment to a grade higher than HIGH_GRADE
			Bureaucrat	c("C", HIGH_GRADE);

			c.incrementGrade();
			std::cout << c << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "TEST 4" << std::endl;
		try
		{
			// Decrement to a grade lower than LOW_GRADE
			Bureaucrat	d("D", LOW_GRADE);

			d.decrementGrade();
			std::cout << d << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 5" << std::endl;
		try 
		{
			// Acceptable grade changes
			Bureaucrat	adolf("ADOLF", 10);

			adolf.decrementGrade();
			std::cout << adolf << std::endl;
			adolf.incrementGrade();
			std::cout << adolf << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}