#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<string>

class ClapTrap
{
	private:
		std::string name_;
		int	hitPoints_;
		int 	energyPoints_;
		int	attackDamage_;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
