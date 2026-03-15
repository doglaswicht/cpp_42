/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:40:54 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/15 18:33:41 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>
#include <ostream>

class Form;

class Bureaucrat
{
	private:
		const std::string name_;
		int	grade_;
	public:
		Bureaucrat (const std::string& name, int grade);
		Bureaucrat (const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		const std::string& getName()const;
		int getGrade()const;
		
		void incrementGrade();
		void decrementGrade();
		void Bureaucrat::signForm(Form& form) const

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif
