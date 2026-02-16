#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "khaled";
    data.age = 22;

    Data* pd = &data;

    std::cout << "Address of data:  " << pd << "\n";
    uintptr_t a = Serializer::serialize(pd);
    std::cout << "uintptr_t value:  " << a << "\n";
    Data* pd1 = Serializer::deserialize(a);
    std::cout << "Address of data1: " << pd1 << "\n\n";

    std::cout << "data1.name = " << pd1->name << "\n";
    std::cout << "data1.age  = " << pd1->age  << "\n";
}
