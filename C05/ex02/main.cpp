/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:11:47 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/17 17:11:49 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Manager", 50);
		Bureaucrat low("Intern", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "\n--- Initial forms ---" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robo << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "\n--- Try execute unsigned form ---" << std::endl;
		boss.executeForm(shrub);

		std::cout << "\n--- Sign forms ---" << std::endl;
		low.signForm(shrub);
		mid.signForm(robo);
		boss.signForm(pardon);

		std::cout << "\n--- Execute forms ---" << std::endl;
		mid.executeForm(shrub);
		mid.executeForm(robo);
		boss.executeForm(pardon);

		std::cout << "\n--- Try with grade too low ---" << std::endl;
		low.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}