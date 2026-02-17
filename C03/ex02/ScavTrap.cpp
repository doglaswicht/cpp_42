#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    name_ = "default";
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "ScavTrap name constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints_ <= 0)
    {
        std::cout << "ScavTrap " << name_ << " can't attack (no hit points left)\n";
        return;
    }
    if (energyPoints_ <= 0)
    {
        std::cout << "ScavTrap " << name_ << " can't attack (no energy points left)\n";
        return;
    }
    energyPoints_--;
    std::cout << "ScavTrap " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode\n";
}
