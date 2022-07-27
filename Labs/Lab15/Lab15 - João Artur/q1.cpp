#include <iostream>

using namespace std;

int main()
{
	float peso;
	peso = 30;
	cout << peso;
	delete peso;
}
// O código é inválido, pois a palavra-chave delete é usada apenas em ponteiros / variáveis com memória alocada dinamicamente.