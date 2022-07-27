#include <iostream>

using namespace std;

int main()
{
	int valor = 10, *temp, soma = 0;	// valor = 10, temp = lixo, soma = 0
	temp = &valor;						// temp = endereço de valor
	*temp = 20;							// item de temp (valor) = 20
	temp = &soma;						// temp = endereço de soma
	*temp = valor;						// item de temp (soma) = valor = 20
										// valor: 20
										// soma: 20
	cout << "valor: " << valor << "\nsoma: " << soma << endl;
}
// tudo certo por aq