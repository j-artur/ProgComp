#include <iostream>

using namespace std;

int main()
{
	int mat[2][3] =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	cout << mat[0][0] << '\n';
	// mat[0][0] aponta para o elemento (0,0) da matriz (int 1).

	cout << mat[0] << '\n';
	// mat[0] aponta para o elemento (0) da matriz (vetor [1, 2, 3]), e o vetor mostra o endereço da sua posição inicial.

	cout << &mat[0][0] << '\n';
	// &mat[0][0] aponta para o endereço do elemento (0,0) da matriz, que é o mesmo endereço do vetor da linha anterior.

	return 0;
}

