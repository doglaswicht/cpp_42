#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        static bool isOperator(const std::string& token);
        static int calculate(int left, int right, char operation);
    public:
        static int evaluate(const std::string& expression);
};

#endif