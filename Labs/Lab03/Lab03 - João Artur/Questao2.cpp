#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "N times table" << endl;
	cout << "-------------" << endl;
	cout << "Insert a number N (from 0 to 9): ";
	cin >> n;

	for (int i = 0; i < 10; i++)
		cout << n << " x " << i << " = " << n * i << endl;
}