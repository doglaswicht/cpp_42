/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:24:00 by dleite-b          #+#    #+#             */
/*   Updated: 2026/03/15 14:27:34 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);


int main()
{
    int N = 10;

    Zombie* horde = zombieHorde(N, "horde");
    
    for(int i = 0; i < N; i++)
    {
        horde[i].announce();   
    }
    delete[] horde;
    return 0;
}