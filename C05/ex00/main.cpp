/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:40:59 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/15 16:41:00 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"

int main()
{
	
	std::cout << " **** Test 1: Valide Bureaucrate ****" << std::endl;
	try
	{
		Bureaucrat a("Doglas", 42);
		std::cout << a << std::endl;
	}
	catch(const std:: exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "**** Test 2: grade too high in constructor ****" << std::endl;
	try
	{
		Bureaucrat b("Bruno", 0);
		std::cout << b << std::endl;
	}
	catch(const std:: exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << "**** Test 3: grade too low in constructor ****" << std::endl;
	try
	{
		Bureaucrat c("Carlos", 152);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	
	std::cout << "****Test 4: Increment grade ****" << std::endl;
	try
	{
		Bureaucrat d("David", 2);
		std::cout << d << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	
	std::cout << "**** Test 5: decrement grade ****" << std::endl;
	try
	{
		Bureaucrat e("Evaldo", 149);
		std::cout << e << std::endl;
		e.decrementGrade();
		std::cout << e << std::endl;
		e.decrementGrade();
		std::cout << e << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return 0;
}
