#include "Serializer.hpp"

int main(void)
{
	Data 	data_before;
	Data* 	data_after;

	data_before.number = 10;
	data_before.text = "Aflred";
	std::cout << "Adresse data_before : " << &data_before << std::endl;
	std::cout << "Number data_before : " << data_before.number << std::endl;
	std::cout << "String data_before : " << data_before.text << std::endl << std::endl;

	uintptr_t value = Serializer::serialize(&data_before);
	data_after = Serializer::deserialize(value);
	std::cout << "Adresse data_after : " << data_after << std::endl;
	std::cout << "Number data_after : " << data_after->number << std::endl;
	std::cout << "String data_after : " << data_after->text << std::endl;

	return 0;
}
