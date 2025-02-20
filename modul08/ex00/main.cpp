#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() 
{
    int arr[] = {10, 20, 30, 40, 50};
    std::vector<int> vec(arr, arr + 5);
    
    try 
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found element: " << *it << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);
   
    try 
    {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found element: " << *it << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    try 
    {
        easyfind(vec, 100);
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
