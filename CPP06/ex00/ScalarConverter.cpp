#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& parent)
{
    (*this) = parent;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &parent)
{
    (void) parent;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::convert(std::string str)
{
    double value = std::atof(str.c_str());
    // need to check for just the char that are affichable
    std::cout << "char: " << showChar(value) << std::endl;
    // std::cout << precisionShow(str.c_str());
}

char showChar(double value)
{
    if ((value > 31) && (value < 127))
        return (static_cast<char> (value));
    else
        return ('a');
        // std::cout << "impossible";
}

int precisionShow(const char *str)
{
    int start = 0;
    int after;

    while (str[start] && str[start] != '.')
        start++;
    after = start + 1;
    while (str[after] && std::isdigit(str[after]))
        after++;
    return (after - start - 1);
}

// char ScalarConverter::strToChar(std::string str) { (void) str;}

// int ScalarConverter::strToInt(std::string str) { (void) str; }

// float ScalarConverter::strToFloat(std::string str) { (void) str; }

// double ScalarConverter::strToDouble(std::string str) { (void) str; }

