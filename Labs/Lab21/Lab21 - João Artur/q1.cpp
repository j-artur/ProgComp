#include <iostream>

using namespace std;

int main()
{
	/*
	* 1. Construa expressões lógicas para representar as seguintes condições:
	* a. ch não é um q nem um k
	* b. idade não está entre 15 e 26
	* c. x é impar e maior que 30
	* d. num é múltiplo de 5 ou de 8
	* e. peso não é menor que 50 e altura é maior que 160
	*/

	char ch = ' ';
	unsigned idade = 20;
	int x = 31;
	int num = 9;
	double peso = 60;
	int altura = 180;

	bool A = (ch != 'q') && (ch != 'k');
	bool B = !(idade >= 15 && idade <= 26);
	bool C = (x % 2) && (x > 30);
	bool D = !(num % 5) || !(num % 8);
	bool E = !(peso < 50) && (altura > 160);

	cout << "a. " << A << '\n';
	cout << "b. " << B << '\n';
	cout << "c. " << C << '\n';
	cout << "d. " << D << '\n';
	cout << "e. " << E << '\n';

	return 0;
}
