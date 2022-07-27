#include <iostream>
using namespace std;

float average(int, int);

int main()
{
	int num1, num2;

	cout << "Insert an integer: ";
	cin >> num1;
	cout << "Insert another integer: ";
	cin >> num2;

	cout << "The average is " << average(num1, num2);
}

float average(int n1, int n2)
{
	float avrg = (n1 + n2) / 2;
	return avrg;
}