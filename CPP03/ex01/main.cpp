#include "ClapTrap.h"
#include "ScavTrap.h"

int main()
{
    ClapTrap clap1("clap1");

    clap1.attack("target");
    clap1.takeDamage(5);
    clap1.beRepaired(50);

    ScavTrap scav1("scav1");

    scav1.attack("target");
    scav1.takeDamage(3);
    scav1.beRepaired(10);
    scav1.guardGate();

    ScavTrap scav2 = scav1;
    scav2.attack("clap1");
    scav2.takeDamage(7);

    ScavTrap scav3("scav3");
    scav3 = scav1;
    scav3.guardGate();
    scav3.beRepaired(5);

    clap1.attack("scav1");
    scav1.takeDamage(15);
    scav1.attack("clap1");

    return 0;
}