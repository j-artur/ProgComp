#include <iostream>

unsigned short lowBits(unsigned int);

int main()
{
	std::cout << "Insert a integer: ";

	unsigned int integer;
	std::cin >> integer;

	std::cout << "The lower bits of this value match the number " << lowBits(integer);
}

unsigned short lowBits(unsigned int integer)
{
	unsigned int mask = 0b00000000000000001111111111111111;

	unsigned short result = integer & mask;

	return result;
}