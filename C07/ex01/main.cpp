/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleite-b <dleite-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:15:28 by dleite-b          #+#    #+#             */
/*   Updated: 2026/06/04 10:22:45 by dleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void increment(T& element)
{
    element++;
}

void toUpperChar(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::string words[] = {"hello", "world", "templates"};
    char letters[] = {'a', 'b', 'c'};

    std::cout << "Numbers:" << std::endl;
    iter(numbers, 5, printElement<int>);

    std::cout << "\nNumbers after increment:" << std::endl;
    iter(numbers, 5, increment<int>);
    iter(numbers, 5, printElement<int>);

    std::cout << "\nWords:" << std::endl;
    iter(words, 3, printElement<std::string>);

    std::cout << "\nLetters before:" << std::endl;
    iter(letters, 3, printElement<char>);

    iter(letters, 3, toUpperChar);

    std::cout << "\nLetters after:" << std::endl;
    iter(letters, 3, printElement<char>);

    return 0;
}