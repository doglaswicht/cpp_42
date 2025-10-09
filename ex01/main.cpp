/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 03:03:28 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/09 12:09:19 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>


int main()
{
    Phonebook phonebook;
    std::string command;
    
    while(true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT)";
        std::getline(std::cin, command);
        
        if(command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH")
            phonebook.searchContact();
        else if(command == "EXIT" || std::cin.eof())
            break;
        else
            std::cout << "Unknow command!" << std::endl;
    }
    return 0;
}