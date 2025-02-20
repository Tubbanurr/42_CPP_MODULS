#include "Span.hpp"

int main() 
{
    try 
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest distance: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest distance: " << sp.longestSpan() << std::endl;

        sp.addNumber(99);
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Span sp(10000);
        std::vector<int> values(10000);
        for (unsigned int i = 0; i < values.size(); i++)
            values[i] = i;
        sp.addNumbers(values.begin(), values.end());

        std::cout << "Shortest distance in 10000 element span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest distance in 10000 element span: " << sp.longestSpan() << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
