/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:14 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/17 10:35:15 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat()
{
	type_ = "Cat";
	std::cout << "[Cat] Default constructor called " << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{std::cout << "[Cat] Copy construtor called" << std::endl;}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	if(this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{std::cout << "[Cat] Destructor called" << std::endl;}

void Cat::makeSound() const
{std::cout << "Meow" << std::endl;}
