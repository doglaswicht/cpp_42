/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 02:19:09 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/01 15:07:33 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include "Contact.hpp"
#include "Phonebook_utils.hpp"

class   Phonebook
{
    private:
        Contact _contacts[8];
        int     _index;
    
    public:
        Phonebook(void);
        ~Phonebook(void);
        void    add(void);
        void    search(void);
        void    print(Contact contact);

        Contact get_contact(int index);    
};

#endif