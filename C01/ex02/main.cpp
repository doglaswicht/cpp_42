/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:22:07 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 12:22:08 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<iostream>
#include <string>

int main()
{
	std::string str= "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
       	std::string& stringREF = str;

	std::cout << "Adresse [String]: " << &str << std::endl;
	std::cout << "Adresse [stringPTR]: "<< stringPTR << std::endl;
	std::cout << "Adresse [StringREF]: "<< &stringREF << std::endl;

	std::cout << "Value: " << str << std::endl;
	std::cout << "Value StringPTR: "  << *stringPTR << std::endl;
	std::cout << "Value StringREF: "  << stringREF << std::endl;

	return 0;
}

