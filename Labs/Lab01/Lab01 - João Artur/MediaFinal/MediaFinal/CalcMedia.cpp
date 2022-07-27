// CalcMedia.cpp - calcula a média das avaliações
#include <iostream>
using namespace std;

int main() {
	system("chcp 1252 > nul");

	float n1, n2, n3, media;

	cout << "Calculando a média" << endl;
	cout << "------------------" << endl;
	cout << endl;
	cout << "Nota 1: ";
	cin >> n1;
	cout << "Nota 2: ";
	cin >> n2;
	cout << "Nota 3: ";
	cin >> n3;
	cout << endl;

	media = (n1 + n2 + n3) / 3;
	cout << "A média parcial é: " << media << endl;

	if (media > 7.0f) cout << "O aluno foi aprovado." << endl;
	else {
		float n4, mediafinal;

		cout << endl;
		cout << "Nota 4: ";
		cin >> n4;

		mediafinal = ((media * 6) + (n4 * 4)) / 10;

		cout << "A média final é: " << mediafinal << endl;
		cout << "O aluno foi " << ((mediafinal >= 5.0f) ? "aprovado." : "reprovado.") << endl;
	}

	return 0;
}