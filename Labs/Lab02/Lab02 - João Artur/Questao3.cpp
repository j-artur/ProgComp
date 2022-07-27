#include <iostream>
#include <locale>
using namespace std;

int main()
{
	locale::global(locale{ "pt-BR" });

	cout << left; cout.width(16); cout << "Produto";
	cout << left; cout.width(16); cout << "Preço/Kg";
	cout << left; cout.width(16); cout << "Pedido (Kg)";
	cout << left; cout.width(16); cout << "Total Parcial";
	cout << endl;

	cout << left; cout.width(16); cout << "-------------";
	cout << left; cout.width(16); cout << "-------------";
	cout << left; cout.width(16); cout << "-------------";
	cout << left; cout.width(16); cout << "-------------";
	cout << endl;

	cout << left; cout.width(16); cout << "Alface";
	cout << left; cout.width(16); cout << "R$ 1,25/Kg";
	cout << left; cout.width(16); cout << "3,2Kg";
	cout << left; cout.width(16); cout << "R$ 4,00";
	cout << endl;

	cout << left; cout.width(16); cout << "Beterraba";
	cout << left; cout.width(16); cout << "R$ 0,65/Kg";
	cout << left; cout.width(16); cout << "6,0Kg";
	cout << left; cout.width(16); cout << "R$ 3,90";
	cout << endl;

	cout << left; cout.width(16); cout << "Cenoura";
	cout << left; cout.width(16); cout << "R$ 0,90/Kg";
	cout << left; cout.width(16); cout << "10Kg";
	cout << left; cout.width(16); cout << "R$ 9,00";
	cout << endl;
}