#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n--- Create ScavTrap default ---\n";
    ScavTrap a;

    std::cout << "\n--- Create ScavTrap named ---\n";
    ScavTrap b("SC4V");

    std::cout << "\n--- Actions ---\n";
    a.attack("TargetA");
    b.attack("TargetB");
    b.guardGate();

    std::cout << "\n--- End (watch destruction order) ---\n";
    return 0;
}
