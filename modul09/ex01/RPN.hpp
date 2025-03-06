#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN 
{
    private:
        std::stack<int> numbers;
        
        bool isOperator(const std::string &token);
        bool isValidNumber(const std::string &token);
        int applyOperation(int a, int b, char op);

    public:
        RPN();
        ~RPN();
        
        int evaluate(const std::string &expression);
};

#endif
