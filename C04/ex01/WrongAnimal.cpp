/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:36:15 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/17 10:36:16 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{std::cout << "[WrongAnimal]  Default constructor called" << std::endl;}


WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_)
{std::cout << "[WrongAnimal] Copy constructor called" << std::endl; }


WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] Copy assignment called" << std::endl;
	if(this != &other)
		type_ = other.type_;
	return *this;
}

WrongAnimal::~WrongAnimal()
{std::cout << "[WrongAnimal] Destructor Called" << std::endl;}

std::string WrongAnimal::getType() const
{return type_;}


void WrongAnimal::makeSound() const
{std::cout << "* wrong generic sound*" << std::endl;}
