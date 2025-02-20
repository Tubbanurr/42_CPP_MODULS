#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm> 
#include <exception> 

template <typename T>
typename T::iterator easyfind(T& container, int value) 
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end()) 
        throw std::runtime_error("Error: The requested element was not found!");

    return it;
}

#endif
