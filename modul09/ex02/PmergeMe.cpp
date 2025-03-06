#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int argc, char **argv) 
{
    for (int i = 1; i < argc; i++) 
    {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++) 
        {
            if (!isdigit(arg[j])) 
            {
                std::cerr << "Error: Invalid input (" << arg << ")" << std::endl;
                exit(1);
            }
        }
        int num = std::atoi(arg.c_str());
        if (num <= 0) 
        {
            std::cerr << "Error: Input must be positive integers only." << std::endl;
            exit(1);
        }
        vectorContainer.push_back(num);
        dequeContainer.push_back(num);
    }
}

void PmergeMe::insertionSortVector(std::vector<int> &vec) 
{
    for (size_t i = 1; i < vec.size(); i++) 
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) 
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int> &deq) 
{
    for (size_t i = 1; i < deq.size(); i++) 
    {
        int key = deq[i];
        int j = i - 1;
        while (j >= 0 && deq[j] > key) 
        {
            deq[j + 1] = deq[j];
            j--;
        }
        deq[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSortVector(std::vector<int> &vec) 
{
    if (vec.size() < 10) 
    {
        insertionSortVector(vec);
        return;
    }

    std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

    mergeInsertionSortVector(left);
    mergeInsertionSortVector(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &deq) 
{
    if (deq.size() < 10)
    {
        insertionSortDeque(deq);
        return;
    }

    std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
    std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());

    mergeInsertionSortDeque(left);
    mergeInsertionSortDeque(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
}

void PmergeMe::printVector() 
{
    size_t size = vectorContainer.size();
    if (size <= 10) 
    {  
        for (size_t i = 0; i < size; i++)
            std::cout << vectorContainer[i] << " ";
    } 
    else 
    {  
        for (size_t i = 0; i < 5; i++) std::cout << vectorContainer[i] << " ";
        std::cout << "[...] ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque() 
{
    size_t size = dequeContainer.size();
    if (size <= 10) 
    {  
        for (size_t i = 0; i < size; i++)
            std::cout << dequeContainer[i] << " ";
    } 
    else 
    {  
        for (size_t i = 0; i < 5; i++) std::cout << dequeContainer[i] << " ";
        std::cout << "[...] ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortAndMeasure() 
{
    std::cout << "Before (Vector): ";
    printVector();

    std::cout << "Before (Deque): ";
    printDeque();

    clock_t start, end;
    double vectorTime, dequeTime;

    start = clock();
    mergeInsertionSortVector(vectorContainer);
    end = clock();
    vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;  

    start = clock();
    mergeInsertionSortDeque(dequeContainer);
    end = clock();
    dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;  

    std::cout << "After (Vector): ";
    printVector();

    std::cout << "After (Deque): ";
    printDeque();

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vectorContainer.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << dequeContainer.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
