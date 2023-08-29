#pragma once
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter(void);

public:
    ScalarConverter(const ScalarConverter& parent);
    ScalarConverter& operator=(const ScalarConverter& parent);
    ~ScalarConverter(void);

	class ImpossibleException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		virtual const char* what() const throw();
	};

	// useful functions 
	static void getChar(double value, std::string org);
	static void getInt(double value, std::string org);
	static void getFloat(double value, std::string org);
	static void getDouble(double value, std::string org);

	static void showItem(std::string type, void (*convert_function)(double value, std::string org), double value, std::string org);
	static int precisionShow(const char *str);
	
    static void convert(std::string str);
};
