/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:33:34 by dleite-b          #+#    #+#             */
/*   Updated: 2026/02/11 15:37:41 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

 #include <iostream>

 class Fixed
 {
    private:
        int _rawBits;
        static const int _fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        
        int getRawBits(void)const;
        void setRawBits(int const raw);
        
 };


 #endif