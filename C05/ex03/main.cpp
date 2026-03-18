/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:11:47 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/18 15:42:37 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm *form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *form2 = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	AForm *form4 = someRandomIntern.makeForm("unknown form", "test");

	if (form1)
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}
	if (form2)
	{
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}
	if (form3)
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}
	if (form4)
		delete form4;

	return 0;
}