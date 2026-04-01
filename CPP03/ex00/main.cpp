#include "ClapTrap.h"

int	main()
{
	ClapTrap clap1("clap1");

	clap1.attack("target");
	clap1.takeDamage(5);
	clap1.beRepaired(50);

	ClapTrap clap2("clap2");
	clap1.attack("clap2");
	clap2.takeDamage(2);

	ClapTrap clap3 = clap2;

	clap2.attack("clap3");
	clap3.takeDamage(8);

	ClapTrap clap4("clap4");
	clap4 = clap1;

	clap1.attack("clap4");
	clap4.takeDamage(5);
	clap4.beRepaired(1);

	clap1.takeDamage(100);
	clap1.attack("target");
	clap1.beRepaired(10);

	clap2.beRepaired(5);
	clap2.attack("clap1");

	clap3.takeDamage(50);
	clap3.attack("clap2");

	return (0);
}