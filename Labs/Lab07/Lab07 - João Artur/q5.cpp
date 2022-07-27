#include <iostream>

void showBits(unsigned char);
bool testBit(unsigned char, unsigned char);

int main()
{
	std::cout << "Insert a number between 0 and 255: ";

	unsigned short number;

	std::cin >> number;

	std::cout << "The number " << number << " in binary is ";
	showBits(number);
}

bool testBit(unsigned char byte, unsigned char position)
{
	unsigned char mask = 1 << position;

	unsigned char result = byte & mask;

	return result;
}

void showBits(unsigned char byte)
{
	for (size_t i = 0; i < 8; i++)
		std::cout << testBit(byte, 7 - i);
}