#include <iostream>
#include "cryptography.h"

int main()
{
	std::cout << "Insert a character: ";

	char character;
	std::cin >> character;

	std::cout << '\n';
	std::cout << "Type 0 to decrypt\n";
	std::cout << "Type 1 to encrypt\n";

	bool action;
	std::cin >> action;

	if (action)
		std::cout << "\nEncrypted char: " << encrypt(character);
	else
		std::cout << "\nDecrypted char: " << decrypt(character);
}