#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        std::string trim(const std::string& str)const;

    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);

        bool isValidValue(const std::string& valueStr, double& value) const;
        bool isValidDate(const std::string& date) const;

        double getExchangeRate(const std::string& date) const;



};

#endif