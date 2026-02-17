/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:36:20 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/17 10:36:21 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type_ = "WrongCat";
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}


WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{std::cout << "[WrongCat] Copy constructor called" << std::endl;}


WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] Copy assignment called" << std::endl;
	if(this != &other)
		WrongAnimal::operator=(other);
	return *this;
}


WrongCat::~WrongCat()
{std::cout << "[WrongCat] Destructor called" << std::endl;}

void WrongCat::makeSound()const
{std::cout << "Meeew ? Je suis un chat ?" << std::endl;}

