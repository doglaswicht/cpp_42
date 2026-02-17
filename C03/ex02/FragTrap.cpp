#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    name_ = "default";
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "FragTrap name constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints_ <= 0)
    {
        std::cout << "FragTrap " << name_ << " can't attack (no hit points left)\n";
        return;
    }
    if (energyPoints_ <= 0)
    {
        std::cout << "FragTrap " << name_ << " can't attack (no energy points left)\n";
        return;
    }
    energyPoints_--;
    std::cout << "FragTrap " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " points of damage!\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name_
              << " requests a positive high five! ✋\n";
}
