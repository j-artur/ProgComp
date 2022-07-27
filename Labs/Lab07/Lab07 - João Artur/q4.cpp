#include <iostream>

unsigned short highBits(unsigned int);

int main()
{
	std::cout << "Insert a integer: ";

	unsigned int integer;
	std::cin >> integer;

	std::cout << "The higher bits of this value match the number " << highBits(integer);
}

unsigned short highBits(unsigned int integer)
{
	unsigned int mask = 0b11111111111111110000000000000000;

	unsigned short result = (integer & mask) >> 16;

	return result;
}
