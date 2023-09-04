#include "MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "Using List" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
	
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	std::cout << std::endl << "Using MutantStack" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		MutantStack<int> s(mstack);
	}
	std::cout << std::endl << "Additional Tests " << std::endl;
	{
		MutantStack<char> mstack;
		mstack.push('a');
		mstack.push('b');
		mstack.push('c');
		mstack.push('d');

		MutantStack<char>::iterator 				begin = mstack.begin();
		MutantStack<char>::const_iterator 			cbegin = mstack.cbegin();
		MutantStack<char>::iterator 				end = mstack.end();
		MutantStack<char>::const_iterator 			cend = mstack.cend();
		MutantStack<char>::reverse_iterator 		rbegin = mstack.rbegin();
		MutantStack<char>::const_reverse_iterator 	crbegin = mstack.crbegin();
		MutantStack<char>::reverse_iterator 		rend = mstack.rend();
		MutantStack<char>::const_reverse_iterator 	crend = mstack.crend();

		std::cout << *begin << std::endl;
		std::cout << *cbegin << std::endl;
		std::cout << *(end - 1) << std::endl;
		std::cout << *(cend - 1) << std::endl;
		std::cout << *rbegin << std::endl;
		std::cout << *crbegin<< std::endl;
		std::cout << *(rend - 1) << std::endl;
		std::cout << *(crend - 1) << std::endl;
	
		/*  
		Explanation of the iterators :

		Begin :
		 	| a | b | c | d | END |
			Begin = A, then go ->

		End :
		 	| a | b | c | d | END |
			End = END (becareful points to the value following the LAST elements), then go ->
	
		Reverse Begin :
			| REND | a | b | c | d |
			Reverse Begin = d , then go <-

		Reverse End :
			| REND | a | b | c | d |
			Reverse Begin = REND (same as end it is AFTER the LAST value) , then go <-

		*/
	}
}
