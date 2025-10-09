/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:08:45 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/09 12:08:49 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip> // pour setw()
void    Contact::setInfo()
{
    std::cout << "First name: ";
    std::getline(std::cin, first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Dark secret: ";
    std::getline(std::cin, darkest_secret);
}

static std::string truncate(const std::string &str)
{
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayShort(int index) const
{
    std::cout   << std::setw(10) << index << "|"
                << std::setw(10) << truncate(first_name) << "|"
                << std::setw(10) << truncate(last_name) << "|"
                << std::setw(10) << truncate(nickname) << "|" << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "NickName: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Dark secret: " << darkest_secret << std::endl;
}