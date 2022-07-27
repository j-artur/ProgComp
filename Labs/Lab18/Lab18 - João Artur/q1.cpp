#include <iostream>

using namespace std;


int main()
{
	int i = 0;
	while (++i < 4) // O 'i' é incrementado antes da operação.
		cout << "Oi! "; // Deve ser executado 3 vezes (1 - 2 - 3)

	do // No do-while o bloco é executado antes e a condicional depois.
		cout << "Tchau! "; // Deve ser executado 6 vezes (4 - 5 - 6 - 7 - 8 - 9)
	while (i++ <= 8);

	// O programa deverá imprimir "Oi!" 3 vezes e "Tchau!" 6 vezes.

	return 0;
}
