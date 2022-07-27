#include <iostream>

using namespace std;

int main() {
	cout << "Enter any invalid operator to exit.\n";

	while (true) {
		double num1;
		char op;
		double num2;
		cout << "Calculate:\n";
		cin >> num1 >> op >> num2;

		switch (op) {
		case '+':
			cout << num1 + num2;
			break;
		case '-':
			cout << num1 - num2;
			break;
		case '*':
			cout << num1 * num2;
			break;
		case '/':
			cout << num1 / num2;
			break;
		default:
			return 0;
		}
		cout << '\n';
	}
}
