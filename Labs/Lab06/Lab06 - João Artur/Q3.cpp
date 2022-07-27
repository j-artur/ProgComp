#include <iostream>

int main()
{
	unsigned short x = 1;
	x = x + 32767;
	std::cout << "x = " << x << std::endl;

	unsigned int y = 2'147'483'647;
	y = y + 1;
	std::cout << "y = " << y << std::endl;

	return 0;
}
/*
* O uso da palavra-chave unsigned muda o comportamento dos tipos inteiros
* para aceitar apenas números naturais, dobrando o valor máximo.
*/