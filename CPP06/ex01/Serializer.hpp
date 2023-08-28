#pragma once
#include <cstdint>
#include <iostream>

struct Data
{
	std::string text;
	int			number;
};

class Serializer
{
private:
	Serializer(void);
public:
	Serializer(const Serializer& parent);
	Serializer& operator=(const Serializer& parent);
	~Serializer(void);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
