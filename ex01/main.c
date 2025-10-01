/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 03:03:28 by dleite-b          #+#    #+#             */
/*   Updated: 2025/10/01 03:07:37 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook ph1;
    std::string str;

    whike(str != "EXIT")
    {
        std::cout << "Enter a command > ";
        std::getline(std::cin, str);
        if(str == "ADD")
            ph1.add();
        else if(str == "SEARCH")
            ph1.search();
        if(std::cin, eof())
        {
            std::cout << std::endl;
            return 0;
        }
    }
    return 0;
}