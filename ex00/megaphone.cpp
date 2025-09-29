/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:27:11 by dleite-b          #+#    #+#             */
/*   Updated: 2025/09/29 09:19:21 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if(argc == 1){std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; return 0;}
    
    while(i < argc)
    {
        while(argv[i][j])
        {
            std::cout << (char) std::toupper(argv[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
     return 0;
}