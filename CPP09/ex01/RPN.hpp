#include <iostream>
#include <stack>
#include <exception>
#include <sstream>

class RPN
{
private:
	std::stack<std::string>	_stack;
public:
	RPN(void);
	RPN(const RPN& parent);
	RPN& operator=(const RPN& parent);
	~RPN(void);

	void		doCalculation(std::string n_list);
	void		checkStringSyntax(std::string string);
	void		checkEachItems(std::string str);
	void		doRPN(void);
	int			doOperation(int left, int right, std::string sign);


	int 		isNumber(std::string str);
	std::string itos(int value);



	class InvalidCharacterException : public std::exception {
		public	:
			virtual const char * what() const throw() { return ("invalid character found !");}
	};

	class HighNumberException : public std::exception {
		public :
			virtual const char * what() const throw() { return ("number too high, should be between 0 and 10 !");}
	};

	class InvalidCalculationSyntaxeException : public std::exception {
		public :
			virtual const char * what() const throw() { return ("syntax of numbers and operator is incorrect !");}
	};

	class IllegalActionException : public std::exception {
		public :
			virtual const char * what() const throw() { return ("i think you tried to do something illegal !");}
	};
};
