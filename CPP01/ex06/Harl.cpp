#include "Harl.h"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \n";
	std::cout << "I really do!\n";
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. \n";
	std::cout << "You didn't put enough bacon in my burger! \n";
	std::cout << "If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. \n";
	std::cout << "I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! \n";
	std::cout << "I want to speak to the manager now.\n";
}

void Harl::complain(const std::string& level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4 && level != levels[i])
		i++;
	switch (i)
	{
		case (0):
			(this->*ptr[0])();
		case (1):
			(this->*ptr[1])();
		case (2):
			(this->*ptr[2])();
		case (3):
			(this->*ptr[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}