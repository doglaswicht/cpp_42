/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:40:45 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/16 16:30:21 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade) {
	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		grade_ = other.grade_;
	return *this;		
}


Bureaucrat::~Bureaucrat(){}


const std::string&  Bureaucrat::getName()const
{return name_;}


int  Bureaucrat::getGrade() const
{return grade_;}

void Bureaucrat::incrementGrade()
{
	if(grade_ <= 1)
		throw GradeTooHighException();
	grade_--;
}

void Bureaucrat::decrementGrade()
{
	if(grade_ >= 150)
		throw GradeTooLowException();
	grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name_ << " couldn't sign "
		          << form.getName()
		          << " because "
		          << e.what()
		          << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return os;
}




