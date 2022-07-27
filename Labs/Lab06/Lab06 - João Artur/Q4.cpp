#include <iostream>
using namespace std;

long long calculo(long long, long long);

int main()
{
	// long long resultado = 200530 * 420800;

	/*
	* Quando são usados dois valores int numa multiplicação,
	* o resultado da expressão assume o tipo int,
	* que depois é atribuído a uma variável long long.
	*/

	long long resultado = 200530LL * 420800;

	/*
	* Ao usar o tipo long long em no mínimo um dos valores da multiplicação,
	* o resultado da expressão assume o tipo long long, por ser o maior na expressão.
	*/

	cout << "Direto: " << resultado << endl;
	cout << "Função: " << calculo(200530, 420800) << endl;
	return 0;
}

/*
* Problema que não ocorre na função abaixo,
* pois os valores usados na multiplicação são ambos do tipo long long.
*/
long long calculo(long long a, long long b)
{
	return a * b;
}
