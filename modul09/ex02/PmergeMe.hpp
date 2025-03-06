#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> vectorContainer;
    std::deque<int> dequeContainer;

    void insertionSortVector(std::vector<int> &vec);
    void insertionSortDeque(std::deque<int> &deq);

    void mergeInsertionSortVector(std::vector<int> &vec);
    void mergeInsertionSortDeque(std::deque<int> &deq);

    void printVector();
    void printDeque();

public:
    PmergeMe();
    ~PmergeMe();
    
    void processInput(int argc, char **argv);

    void sortAndMeasure();
};

#endif
