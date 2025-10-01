/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:49:45 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/01 03:02:57 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP

# define PHONEBOOK_UTILS_HPP

# include <iostream>
# include "Contact.hpp"

//Retorna uma string com n espacos
std::string add_spaces(int n);

// Ensures a string has most max chars, adding '.' quando necessario
std::string fix_width(std::string str, long unsigned max);

//Imprime contatos existentes com o melhor formato
int search_ui(Contact contact[8]);

#endif