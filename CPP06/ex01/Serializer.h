#pragma once

#include <stdint.h>
#include "Data.h"

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& other);
	~Serializer();
};
