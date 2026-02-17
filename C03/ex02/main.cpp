#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- Create FragTrap ---\n";
    FragTrap f("FR4G");

    std::cout << "\n--- FragTrap Actions ---\n";
    f.attack("Target");
    f.highFivesGuys();

    std::cout << "\n--- End of scope ---\n";
    return 0;
}
