#include <iostream>
#include <stack>
#include <exception>

class RPN
{
private:
	std::stack<std::string>	_stack;
public:
	RPN(void);
	RPN(const RPN& parent);
	RPN& operator=(const RPN& parent);
	~RPN(void);

	void	doCalculation(std::string n_list);
	void	checkStringSyntax(std::string string);


	class InvalidCharacterException : public std::exception {
		public	:
			virtual const char * what() const throw() { return ("invalid character found !");}
	};
};
