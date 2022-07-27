#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string num1s;
	int num1 = 0;
	int num2 = 0;

	cout << "Insert two integers: ";
	cin >> num1s;
	num1 = stoi(num1s);
	cin >> num2;

	cout << "The product of them is " << num1 * num2 << '\n';

	return 0;
}
