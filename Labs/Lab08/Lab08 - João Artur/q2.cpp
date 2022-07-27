#include <iostream>

using namespace std;

unsigned int mask(unsigned char);
void findFloat(unsigned int);

/* 11001000001100010100000000000000
* 
* 11001000       0      01100010100000000000000
* Expoente     Sinal           Mantissa
* 
* 0b11001000 = 200
* Expoente = 200
* e = 200
* (e - 127) = 200 - 127 = 73
* 
* Sinal = +
* s = (+1)
* 
* Mantissa = 0.25 + 0.125 + 0.0078125 + 0.001953125
* m = 0.384765625
* 
* v = (s) * 2^(e - 127) * (1 + m)
* Valor = (+1) * 2^73 * 1.384765625
* 
* Valor = 13 078 741 548 260 072 095 744
* 
* Apesar de ser um número com muitos dígitos significativos, sua representação em tipo float é 100% precisa.
*/

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);

	float number = 0b11001000001100010100000000000000;

	cout << number << '\n';

	findFloat(number);
}

unsigned int mask(unsigned char pos)
{
	unsigned int mask = 1 << pos;

	return mask;
}

void findFloat(unsigned int number)
{
	bool sign = number & mask(8);

	cout << "Sign: " << (sign ? '-' : '+') << '\n'; 

	unsigned char exp = 0;

	cout << "Exponent: ";

	for (size_t i = 0; i < 8; i++)
	{
		exp = exp << 1;
		bool bit = number & mask(31 - i);

		cout << bit;

		exp += bit;
	}
	cout << " (" << exp - 127 << ")\n";

	float mantissa = 0;

	cout << "Mantissa: ";

	for (size_t i = 0; i < 23; i++)
	{
		bool bit = number & mask(22 - i);
		mantissa += bit * 1 / pow(2, i + 1);

		cout << bit;
	}
	cout << " (" << mantissa << ")\n";

	short newExp = exp - 127;
	cout << "2^" << newExp << " = " << pow(2, newExp) << '\n';

	float decimal = 1 + mantissa;
	cout << "1 + " << mantissa << " = " << decimal << '\n';

	float finalNumber = pow(2, newExp) * decimal;
	cout << "2^" << newExp << " * " << decimal << " = ";
	cout << finalNumber;
}