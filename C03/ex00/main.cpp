#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a("Mr_Robot");
    ClapTrap b("Elliot Anderlson");

    std::cout << "\n--- Attack Test ---\n";
    a.attack("Elliot Anderlson");

    std::cout << "\n--- Damage Test ---\n";
    a.takeDamage(5);

    std::cout << "\n--- Repair Test ---\n";
    a.beRepaired(3);

    std::cout << "\n--- Energy Drain Test ---\n";
    for (int i = 0; i < 11; i++)
        a.attack("Evil Corp");

    std::cout << "\n--- Copy Constructor Test ---\n";
    ClapTrap c(a);

    std::cout << "\n--- Assignment Operator Test ---\n";
    b = a;

    std::cout << "\n--- Destroy Test ---\n";
    return 0;
}

