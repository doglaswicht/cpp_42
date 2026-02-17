#include "Animal.hpp"

Animal::Animal() : type_("Animal")
{std::cout << "[Animal] Default constructor called" << std::endl;}

Animal::Animal(const Animal& other)  : type_(other.type_)
{std::cout << "[Animal] Copy constructor called" << std::endl;}


Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] Copy assignment called" << std::endl;
	if(this != &other)
		type_ = other.type_;
	return *this;
			       
}

Animal::~Animal()
{std::cout << "[Animal] Destructor called" << std::endl;}

std::string Animal::getType() const
{return type_;}

void Animal::makeSound()const
{std::cout << "*genec animal sound*" << std::endl;}
