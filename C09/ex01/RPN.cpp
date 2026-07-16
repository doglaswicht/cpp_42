#include "RPN.hpp"

bool RPN::isOperator(const std::string& token)
{
    if (token.length() != 1)
        return false;

    return token[0] == '+'
        || token[0] == '-'
        || token[0] == '*'
        || token[0] == '/';
}

int RPN::calculate(int left, int right, char operation)
{
    if (operation == '+')
        return left + right;

    if (operation == '-')
        return left - right;

    if (operation == '*')
        return left * right;

    if (operation == '/')
    {
        if (right == 0)
            throw std::runtime_error("Error");
        return left / right;
    }

    throw std::runtime_error("Error");
}


int RPN::evaluate(const std::string& expression)
{
    std::stack<int> numbers;
    std::istringstream stream(expression);
    std::string token;

    while (stream >> token)
    {
        if (token.length() == 1
            && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            numbers.push(token[0] - '0');
        }
        else if (isOperator(token))
        {
            if (numbers.size() < 2)
                throw std::runtime_error("Error");

            int right = numbers.top();
            numbers.pop();

            int left = numbers.top();
            numbers.pop();

            int result = calculate(left, right, token[0]);

            numbers.push(result);
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (numbers.size() != 1)
        throw std::runtime_error("Error");

    return numbers.top();
}