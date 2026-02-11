/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:23:13 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 12:23:14 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
 #define WEAPON_HPP

#include <string>


class Weapon
{
	private:
		std::string type_;
	
	public:
		Weapon(const std::string& type);

		const std::string& getType() const;
		void setType(const std::string& type);

};


#endif
