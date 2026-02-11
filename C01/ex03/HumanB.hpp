/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:22:59 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 12:23:00 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name_;
		Weapon* weapon_;
	public:
		HumanB(const std::string& name);
		
		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif
