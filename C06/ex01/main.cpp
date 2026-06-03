/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:17 by dleite-b          #+#    #+#             */
/*   Updated: 2026/06/03 12:39:18 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data(100);

    uintptr_t raw = Serializer::serialize(&data);

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original  : " << &data << std::endl;
    std::cout << "Recovered : " << recovered << std::endl;
    std::cout << "Equal     : " << (&data == recovered) << std::endl;
    std::cout << "Value     : " << recovered->id << std::endl;

    return 0;
}