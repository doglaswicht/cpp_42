#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if(this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

std::string BitcoinExchange::trim(const std::string& str)const
{
    std::string::size_type start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";
    std::string::size_type end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);

}


void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if(!file.is_open())
        throw std::runtime_error("Error: could not open database.");
    
    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line))
    {
        size_t comma = line.find(',');
        if(comma == std::string::npos)
            continue;
    

        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);

        double rate = std::atof(rateStr.c_str());
        _database[date] = rate;
    }
    file.close();
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    if (valueStr.empty())
    {
        std::cout << "Error: bad input => "
                  << valueStr << std::endl;
        return false;
    }
    
    char* end;

    value = std::strtod(valueStr.c_str(), &end);

    if(*end != '\0')
    {
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if(value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if(value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)const
{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    for(int i = 0; i < 10; i++)
    {
        if(i == 4 || i == 7)
            continue;
        if(!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year <= 0)
        return false;
    
    if(month < 1 || month > 12)
        return false;

    if(day < 1 || day > 31)
        return false;
    
    int daysInMonth[] = {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31};

    bool leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    
    if(leapYear)
        daysInMonth[1] = 29;
    if(day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;

}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pipe = line.find('|');

        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipe));
        std::string valueStr = trim(line.substr(pipe + 1));

        if(!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        double value;
        
        if (!isValidValue(valueStr, value))
            continue;

        try
        {
            double rate = getExchangeRate(date);
            double result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date)const
{
    std::map<std::string, double>::const_iterator it;
    it = _database.lower_bound(date);
    if (it != _database.end() && it->first == date)
        return it->second;
    if(it == _database.begin())
        throw std::runtime_error("Error: no exchange rate available.");
    --it;
    return it->second;
}

