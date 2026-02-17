/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:19 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/17 10:35:20 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type_= "Dog";
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{std::cout << "[Dog] Copy constructor called" << std::endl;}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] Copy assignment called" << std::endl;
	if(this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{std::cout << "[Dog] Destructor called " << std::endl;}

void Dog::makeSound() const
{std::cout << "Woof" << std::endl;}
