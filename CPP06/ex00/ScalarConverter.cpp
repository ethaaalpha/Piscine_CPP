#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& parent)
{
    (*this) = parent;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &parent)
{
    (void) parent;
    return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

const char* ScalarConverter::ImpossibleException::what(void) const throw()
{
	return ("Impossible");
}

const char* ScalarConverter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}

void ScalarConverter::convert(std::string str)
{
    double value = std::atof(str.c_str());
	showItem("char", ScalarConverter::getChar, value, str);
	showItem("int", ScalarConverter::getInt, value, str);
	showItem("float", ScalarConverter::getFloat, value, str);
	showItem("double", ScalarConverter::getDouble, value, str);
}

void ScalarConverter::showItem(std::string type, void (*convert_function)(double value, std::string org), double value, std::string org)
{
	std::cout << type << ": ";
	try {
		convert_function(value, org);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::getChar(double value, std::string org)
{
	(void) org;
	if (org == "nan" || org == "nanf" || org == "+inf" || org == "+inff" || org == "-inf" || org == "-inff")
		throw (ScalarConverter::ImpossibleException());
	if ((value < 0) || (value > 255))
        throw (ScalarConverter::ImpossibleException());
   	else if ((value < 31) || (value > 127))
		throw (ScalarConverter::NonDisplayableException()); 
	std::cout << "'" <<  static_cast<char> (value) << "'" << std::endl;
}

void ScalarConverter::getInt(double value, std::string org)
{
	int i = 0;

	if (org == "nan" || org == "nanf" || org == "+inf" || org == "+inff" || org == "-inf" || org == "-inff")
		throw (ScalarConverter::ImpossibleException());
	if ((org.at(i) == '-' || org.at(i) == '+') && org.length() > 1)
		i++;
	if (org.at(i) != '0' && value == 0)
		throw (ScalarConverter::ImpossibleException());
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		throw (ScalarConverter::ImpossibleException());
	std::cout << static_cast<int> (value) << std::endl;
}

void ScalarConverter::getFloat(double value, std::string org)
{
	int i = 0;

	if (org == "nanf" || org == "-inff" || org == "+inff")
	{
		std::cout << org << std::endl;
		return ;
	}
	if ((org.at(i) == '-' || org.at(i) == '+') && org.length() > 1)
		i++;
	if (org.at(i) != '0' && value == 0)
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (floor(value) == value)
	{
		std::cout << value << ".0f" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<float>::min())
		std::cout << "-inff" << std::endl;
	else if ( value > std::numeric_limits<float>::max())
		std::cout << "+inff" << std::endl;
	else
	{
		float newValue = static_cast<float> (value);
		std::cout << std::setprecision(precisionShow(org.c_str()));
		std::cout << newValue << "f" << std::endl;
	}
}

void ScalarConverter::getDouble(double value, std::string org)
{
	int i = 0;

	if (org == "nan" || org == "-inf" || org == "+inf")
	{
		std::cout << org << std::endl;
		return ;
	}
	if ((org.at(i) == '-' || org.at(i) == '+') && org.length() > 1)
		i++;
	if (org.at(i) != '0' && value == 0)
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (floor(value) == value)
	{
		std::cout << value << ".0" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<double>::min())
		std::cout << "-inff" << std::endl;
	else if (value > std::numeric_limits<double>::max())
		std::cout << "+inff" << std::endl;
	else
	{
		std::cout << std::setprecision(precisionShow(org.c_str()));
		std::cout << static_cast<double> (value) << std::endl;
	}
}

int ScalarConverter::precisionShow(const char *str)
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