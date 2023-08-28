#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter(void);
    
public:
    ScalarConverter(const ScalarConverter& parent);
    ScalarConverter& operator=(const ScalarConverter& parent);
    ~ScalarConverter(void);

    static void convert(std::string str);
};

std::string getType(std::string str);
int isChar(std::string str);
int isInt(std::string str);
int isFloat(std::string str);
int isDouble(std::string str);
int precisionShow(const char *str);
char showChar(double value);