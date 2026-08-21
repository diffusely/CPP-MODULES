#include "Serializer.h"
#include <iostream>

int main()
{
    Data original;
    original.name = "test";
    original.value = 42;

    uintptr_t raw = Serializer::serialize(&original);
    Data* back = Serializer::deserialize(raw);

    std::cout << "same address: " << (&original == back) << std::endl;
    std::cout << "name: " << back->name << ", value: " << back->value << std::endl;
    return 0;
}
