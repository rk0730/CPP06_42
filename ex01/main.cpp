#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.n = 42;

	if (data.n == Serializer::deserialize(Serializer::serialize(&data))->n)
		std::cout << "Serialization and deserialization successful!" << std::endl;

	return 0;
}
