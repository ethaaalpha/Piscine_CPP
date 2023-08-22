#include "Form.hpp"

int main(void)
{
	Bureaucrat agent = Bureaucrat("Christine", 130);
	std::cout << agent << std::endl;

	try {
		Form fm_toohigh = Form("FormA1", 0, 100);
		std::cout << fm_toohigh;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_toohigh2 = Form("FormA1", 1, 0);
		std::cout << fm_toohigh2;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_toolow = Form("FormA1", 151, 100);
		std::cout << fm_toolow;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_toolow2 = Form("FormA1", 100, 151);
		std::cout << fm_toolow2;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_fail_to_sign = Form("FormA2", 120, 10);
		std::cout << fm_fail_to_sign;
		fm_fail_to_sign.beSigned(agent);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_fail_achieve_to_sign = Form("FormA2", 130, 10);
		std::cout << fm_fail_achieve_to_sign;
		fm_fail_achieve_to_sign.beSigned(agent);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_fail_fail_to_sign2 = Form("FormA2", 120, 10);
		std::cout << fm_fail_fail_to_sign2;
		agent.signForm(fm_fail_fail_to_sign2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Form fm_fail_achieve_to_sign2 = Form("FormA2", 130, 10);
		std::cout << fm_fail_achieve_to_sign2;
		agent.signForm(fm_fail_achieve_to_sign2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
