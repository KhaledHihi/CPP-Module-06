#pragma once

#include <stdint.h>
#include <iostream>
#include <string>

typedef struct Data_t
{
	std::string name;
	int age;
} Data;


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
