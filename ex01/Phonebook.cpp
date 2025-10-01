/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:03:29 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/01 03:16:20 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Phonebook_utils.hpp"

Phonebook::Phonebook(void)
{
    this->_index = 0;
    std::cout << \
    "Bom vindo a sua agenda, aceita ate oito contatos " \
    << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "See you soon! " << std::endl;
}

void    Phonebook::add(void)
{
    std::string str;

    str = "";
    if(this->index > 7)
        std::cout << "Warning, overwriting if about" << this->_contacts[this->_index % 8].get_fname() << std::endl;
}