#pragma once

#include <stdint.h>
#include <iostream>

typedef struct Data_t
{
	std::string name;
	int age;
} Data;


class Serialization
{
	private:
		Serialization();
		Serialization(const Serialization &other);
		Serialization& operator=(const Serialization &other);
		~Serialization();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
