/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:50:30 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/03 16:45:31 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
        return 0;
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::string str = argv[i];
            for(size_t j = 0; j < str.length(); j++)
            {
                std::cout << (char)std::toupper((unsigned char)str[j]);
            }
        }
    }
    std::cout << std::endl;
    return 0;
}