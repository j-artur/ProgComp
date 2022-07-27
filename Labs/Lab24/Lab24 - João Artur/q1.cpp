#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream txtout;
	ofstream binout;

	// Em arquivos binários, um número inteiro é salvo com tamanho diferente para cada tipo:
	// __int16 -> 16 bits (2 bytes)
	// __int32 -> 32 bits (4 bytes)
	// __int64 -> 64 bits (8 bytes)

	// Em um arquivo de texto, o tamanho do número depende da quantidade de dígitos.
	// Pois cada dígito é representado por um caractere, que tem tamanho 8 bits (1 byte).
	// Por exemplo:
	// De 0 a 9 o número ocupa 8 bits.
	// De 10 a 99, o número ocupa 16 bits.
	// De 100 a 999, o número ocupa 24 bits.

	txtout.open("q1_16.txt");
	binout.open("q1_16.dat", ios_base::binary);

	for (__int16 i = 0; i < 100; i++) {
		txtout << i << ' ';
		binout.write((char*)(&i), sizeof(__int16));
	}

	txtout.close();
	binout.close();

	txtout.open("q1_32.txt");
	binout.open("q1_32.dat", ios_base::binary);

	for (__int32 i = 0; i < 100; i++) {
		txtout << i << ' ';
		binout.write((char*)(&i), sizeof(__int32));
	}

	txtout.close();
	binout.close();

	txtout.open("q1_64.txt");
	binout.open("q1_64.dat", ios_base::binary);

	for (__int64 i = 0; i < 100; i++) {
		txtout << i << ' ';
		binout.write((char*)(&i), sizeof(__int64));
	}

	txtout.close();
	binout.close();

	return 0;
}
