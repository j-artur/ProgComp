#include <iostream>
#include "cryptography.h"

int main()
{
	std::cout << "Insert a character: ";

	char character;
	std::cin >> character;

	std::cout << "Encrypted character: " << encrypt(character) << '\n';
	std::cout << "Decrypted character: " << decrypt(character) << '\n';
}