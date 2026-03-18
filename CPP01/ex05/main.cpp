#include "Harl.h"

int	main(void)
{
	Harl harl;

	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");

	return (0);
}