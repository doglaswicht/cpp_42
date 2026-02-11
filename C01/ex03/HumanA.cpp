/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:22:49 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 12:22:50 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: name_(name), weapon_(weapon) {}

void HumanA::attack() const
{std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;}
