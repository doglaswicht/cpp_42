/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:24:00 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/08 22:44:51 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    randomChump("StackZombie");

    delete heapZombie;
    return 0;
}
