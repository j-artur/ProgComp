#include <iostream>

using namespace std;

bool isPrime(int);
int getNextPrime(int);

int main()
{
	int firstPrime = 2;
	int nthPrime = firstPrime;

	for (size_t primeCount = 1; primeCount < 10001; primeCount++)
		nthPrime = getNextPrime(nthPrime);

	cout << nthPrime;

	return 0;
}

bool isPrime(int number) {
	for (int i = 2; i < number; i++)
		if (number % i == 0)
			return false;

	return true;
}

int getNextPrime(int number) {
	int nextPrime = number + 1;

	while (!isPrime(nextPrime))
		nextPrime++;

	return nextPrime;
}
