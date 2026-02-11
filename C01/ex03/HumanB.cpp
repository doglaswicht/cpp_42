/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:22:57 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 12:22:58 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
	: name_(name), weapon_(NULL) {}

void HumanB::setWeapon(Weapon& weapon)
	{weapon_ = &weapon;}	


void HumanB::attack() const
{
	if(weapon_ == NULL)
	{
		std::cout << name_ << " attacks with no weapon " << std::endl;
		return;
	}
	std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}


