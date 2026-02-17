/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:36:42 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/17 10:36:43 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog()
{
	type_= "Dog";
	brain_ = new Brain();
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	brain_= new Brain(*other.brain_);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] Copy assignment called" << std::endl;
	if(this != &other)
	{
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}	
	return *this;
}

Dog::~Dog()
{
	delete brain_;
	std::cout << "[Dog] Destructor called " << std::endl;
}

void Dog::makeSound() const
{std::cout << "Woof" << std::endl;}

void Dog::setIdea(int i, const std::string& idea)
{
	brain_->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
	return brain_->getIdea(i);
}
