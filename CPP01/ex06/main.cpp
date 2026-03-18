#include "Harl.h"

int	main(int argc, char** argv)
{
	Harl harl;

	if (argc != 2) {
		std::cerr << "usage: <type>";
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}