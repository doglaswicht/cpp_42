/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:48:33 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:18 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::get_fname(void) const
{
    return(this->_fname);
}

std::string Contact::get_lname(void) const
{
    return(this->_lname);
}

std::string Contact::get_nick(void) const
{
    return (this->_nick);
}

std::string Contact::get_phone_num(void) const
{
    return(this->_phone_num);
}

std::string Contact::get_secret(void) const
{
    return(this->_secret);
}

void    Contact::set_fname(std::string str)
{
    this->_fname = str;
}

void    Contact::set_lname(std::string str)
{
    this->_lname = str;
}

void    Contact::set_nick(std::string str)
{
    this->_nick = str;
}

void    Contact::set_phone_num(std::string str)
{
    this->_phone_num = str;
}

void    Contact::set_secret(std::string str)
{
    this->_secret = str;
}
