#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of numbers." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.processInput(argc, argv);
    sorter.sortAndMeasure();

    return 0;
}
