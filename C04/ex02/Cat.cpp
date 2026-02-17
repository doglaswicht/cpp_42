#include "Cat.hpp"


Cat::Cat()
{
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << "[Cat] Default constructor called " << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	brain_ = new Brain(*other.brain_);
	std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] Copy assignment called" << std::endl;
	if(this != &other)
	{
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain_;
	std::cout << "[Cat] Destructor called" << std::endl;
}

void Cat::makeSound() const
{std::cout << "Meow" << std::endl;}


void Cat::setIdea(int i, const std::string& idea)
{
	brain_->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
	return brain_->getIdea(i);
}
