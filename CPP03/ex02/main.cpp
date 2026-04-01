#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include <iostream>

int main()
{
    std::cout << "=== Creating ClapTrap ===\n";
    ClapTrap clap1("Clap1");
    clap1.attack("TargetA");
    clap1.takeDamage(5);
    clap1.beRepaired(10);

    ClapTrap clap2("Clap2");
    clap1.attack("Clap2");
    clap2.takeDamage(2);

    ClapTrap clap3 = clap2;
    clap3.attack("Clap1");
    clap1.takeDamage(3);

    clap1 = clap2;
    clap1.attack("TargetB");

    std::cout << "\n=== Creating ScavTrap ===\n";
    ScavTrap scav1("Scav1");
    scav1.attack("Enemy");
    scav1.takeDamage(15);
    scav1.beRepaired(20);
    scav1.guardGate();

    ScavTrap scav2 = scav1;
    scav2.attack("Enemy2");
    scav2.takeDamage(10);

    scav1 = scav2;
    scav1.guardGate();

    std::cout << "\n=== Creating FragTrap ===\n";
    FragTrap frag1("Frag1");
    frag1.attack("Boss");
    frag1.takeDamage(25);
    frag1.beRepaired(30);
    frag1.highFivesGuys();

    FragTrap frag2 = frag1;
    frag2.attack("Boss2");
    frag2.highFivesGuys();

    frag1 = frag2;
    frag1.highFivesGuys();

    std::cout << "\n=== Testing dead/energy cases ===\n";
    ClapTrap deadClap("DeadClap");
    deadClap.takeDamage(100);
    deadClap.attack("Nothing");
    deadClap.beRepaired(10);

    FragTrap tiredFrag("TiredFrag");
    tiredFrag.attack("Enemy");
    tiredFrag.highFivesGuys();

    return 0;
}