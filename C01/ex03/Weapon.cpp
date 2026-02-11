/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:23:10 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 12:23:11 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type_(type) {}

const std::string& Weapon::getType() const
{
	return type_;
}


void Weapon::setType(const std::string& type)
{
	type_ = type;
}
