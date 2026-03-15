/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:46:00 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/15 19:03:40 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) : name_(name), isSigned_(false) gradeToSign_(gradeTosign), gradeToExec_(gradeToExec) {
    if(gradeToSign_ < 1 || gradeToExec_ < 1)
        throw GradeTooHighException();
    if(gradeToSign_ > 150 || gradeToExec_ > 150)
        throw GradeTooLowExecption();
}

Form::Form(const Form& other) : name_(other.name_),gradeToSign_(other.gradeTosign_), gradeToExec_(other.gradeToExec_) {}

Form&::Form::operator=(const Form& other)
{
    if(this!= other)
        is_signed = other.isSigned_;
    return *this;
        
}

Form::~Form(){}

const std::string& getName(){
    return name_;
}

bool Form::getIsSigned() const{
    return is_signed;
}
int Form::getGradeTosign(){
    return gradeTosign_;
}
int Form::getGradeToExec()const{
    return gradeToExec_;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign_)
		throw GradeTooLowException();

	isSigned_ = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
    os << "Form " << other.getName() << ", signed: " << other.getIsSigned() << ", grade to sign: " << other.getGradeToSign << ", grade to execute: " << other.getGradeToExec();
    return os;
}