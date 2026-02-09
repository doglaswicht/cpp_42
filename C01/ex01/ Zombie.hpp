/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Zombie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:23:55 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/08 22:42:15 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
    private:
    std::string name_;

    public:
        Zombie();
        ~Zombie();
        
        void announce(void);
        Zombie* zombieHorde(int N, std::string name);


};

#endif