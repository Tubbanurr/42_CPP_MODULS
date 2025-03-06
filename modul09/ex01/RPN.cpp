#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) 
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const std::string &token) 
{
    if (token.length() != 1 || token[0] < '0' || token[0] > '9')
        return false;
    return true;
}

int RPN::applyOperation(int a, int b, char op) 
{
    switch (op) 
    {
        case '+': 
            return a + b;
        case '-': 
            return a - b;
        case '*': 
            return a * b;
        case '/': 
            if (b == 0)
                throw std::runtime_error("Error: Division by zero.");
            return a / b;
        default:
            throw std::runtime_error("Error: Invalid operator.");
    }
}

int RPN::evaluate(const std::string &expression) 
{
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isValidNumber(token)) 
            numbers.push(std::atoi(token.c_str())); 
        else if (isOperator(token)) 
        {
            if (numbers.size() < 2) 
                throw std::runtime_error("Error: Not enough numbers for operation.");

            int a = numbers.top(); 
            numbers.pop();
            int b = numbers.top(); 
            numbers.pop();
            int result = applyOperation(b, a, token[0]);
            numbers.push(result);
        } 
        else
            throw std::runtime_error("Error");
    }

    if (numbers.size() != 1)
        throw std::runtime_error("Error: Too many numbers left after operations.");

    return numbers.top();
}
