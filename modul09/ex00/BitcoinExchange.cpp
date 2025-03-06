#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) 
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
        return false;

    int year, month, day;
    std::istringstream ss(date);
    char dash1, dash2;
    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') 
        return false;

    if (year < 2009 || year > 2025) 
        return false;

    if (month < 1 || month > 12)
        return false;

    if (year == 2009 && month == 1 && day == 1)
        return false;

    int daysInMonth[] = { 31, (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28,
                          31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day < 1 || day > daysInMonth[month - 1]) 
        return  false;

    return true;
}

int BitcoinExchange::isValidValue(const std::string &value) 
{
    std::istringstream ss(value);
    double num;
    
    if (!(ss >> num))
        return -1;
    
    if (num < 0)
        return 0;
    
    if (num > 1000)
        return 1; 

    return 2;
}

bool BitcoinExchange::loadDatabase(const std::string &filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: Could not open database file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream ss(line);
        std::string date;
        double price;

        if (std::getline(ss, date, ',') && ss >> price)
            btcRates[date] = price;
    }
    file.close();
    return true;
}

double BitcoinExchange::getBitcoinRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = btcRates.lower_bound(date);

    if (it == btcRates.end())
        --it;
    else if (it->first != date && it != btcRates.begin())
        --it;

    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }

    std::string line;
    bool firstLineChecked = false;

    while (std::getline(file, line)) 
    {
        if (!firstLineChecked) 
        {
            firstLineChecked = true;
            if (line != "date | value") 
            {
                std::cerr << "Error: Input file format is incorrect. First line must be 'date | value'." << std::endl;
                return;
            }
            continue;
        }

        std::istringstream ss(line);
        std::string date, valueStr;
        double value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) 
        {
            date.erase(date.find_last_not_of(" ") + 1);
            date.erase(0, date.find_first_not_of(" "));
            valueStr.erase(valueStr.find_last_not_of(" ") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" "));

            if (!isValidDate(date)) 
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            int valueCheck = isValidValue(valueStr);
            if (valueCheck == -1) 
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (valueCheck == 0) 
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (valueCheck == 1) 
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            value = std::atof(valueStr.c_str());
            double rate = getBitcoinRate(date);
            

            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } 
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    file.close();
}
