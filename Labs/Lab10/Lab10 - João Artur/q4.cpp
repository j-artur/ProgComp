#include <iostream>

int main()
{
	int arr[5];

	for (size_t i = 0; i < 50; i++)
		arr[i] = 10 * (i + 1);

	return 0;
}

/*  Essa posição é sempre a mesma? O que podemos deduzir desse experimento?
*
* O SO não chegou a interferir, mas o VStudio exibiu um erro ao final do programa:
* Runtime check failure #2 - Stack around the variable 'arr' was corrupted.
*
* Pesquisando no google descobri que o C/C++ não faz verificação de limite quando usando vetores.
*
* Tentar acessar uma posição fora do limite do array apenas vai acessar outra parte da memória alocada.
* Durante a execução no VStudio, não ocorreu nada grave pois há uma memória alocada maior do que o programa precisa para rodar.
* Caso fosse executado a partir de um .exe, o programa tentaria acessar e sobrescrever partes da memória
* correspondentes a outros processos rodando no computador, e isso pode ser muito perigoso.
*/