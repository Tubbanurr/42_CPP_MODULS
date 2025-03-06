#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <climits>

class BitcoinExchange 
{
    private:
        std::map<std::string, double> btcRates;
        bool isValidDate(const std::string &date);
        int  isValidValue(const std::string &value);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        
        bool loadDatabase(const std::string &filename);
        double getBitcoinRate(const std::string &date);
        void processInputFile(const std::string &filename); 
};

#endif
