#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Error: Please provide an input file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    if (!btc.loadDatabase("data.csv")) {
        return 1;
    }

    btc.processInputFile(argv[1]);

    return 0;
}
