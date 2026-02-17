#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_("default"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called\n";
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called\n";
    if (this != &other)
    {
        name_ = other.name_;
        hitPoints_ = other.hitPoints_;
        energyPoints_ = other.energyPoints_;
        attackDamage_ = other.attackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints_ <= 0)
    {
        std::cout << "ClapTrap " << name_ << " can't attack (no hit points left)\n";
        return;
    }
    if (energyPoints_ <= 0)
    {
        std::cout << "ClapTrap " << name_ << " can't attack (no energy points left)\n";
        return;
    }
    energyPoints_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target
              << ", causing " << attackDamage_ << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ <= 0)
    {
        std::cout << "ClapTrap " << name_ << " is already destroyed\n";
        return;
    }

    hitPoints_ -= static_cast<int>(amount);
    if (hitPoints_ < 0)
        hitPoints_ = 0;

    std::cout << "ClapTrap " << name_ << " takes " << amount
              << " points of damage! (HP: " << hitPoints_ << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints_ <= 0)
    {
        std::cout << "ClapTrap " << name_ << " can't repair (no hit points left)\n";
        return;
    }
    if (energyPoints_ <= 0)
    {
        std::cout << "ClapTrap " << name_ << " can't repair (no energy points left)\n";
        return;
    }

    energyPoints_--;
    hitPoints_ += static_cast<int>(amount);

    std::cout << "ClapTrap " << name_ << " repairs itself for " << amount
              << " hit points! (HP: " << hitPoints_ << ")\n";
}
