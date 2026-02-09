/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Zombie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:23:58 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/08 22:29:01 by dleite-b         ###   ########.fr       */
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
    
    
};

#endif
