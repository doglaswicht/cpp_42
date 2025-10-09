/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:03:29 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/09 12:11:13 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <limits> //pour gerer les erreurs d'entree
#include <iomanip>

Phonebook::Phonebook() : count(0) {}

void Phonebook::addContact()
{
    int index = count % 8;
    contacts[index].setInfo();
    count++;
}

void Phonebook::searchContact() const
{
    if(count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nick Name" << std::endl;

    for(int i = 0; i < std::min(count, 8); i++)
        contacts[i].displayShort(i);
    
    std::cout << "Enter Index: ";
    
    int index;
    
    if(!(std::cin >> index) || index < 0 || index >= std::min(count, 8))
    {
        std::cout << "Invalid Index! " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore();
    contacts[index].displayFull();
}