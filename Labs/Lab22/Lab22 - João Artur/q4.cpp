#include <iostream>

using namespace std;

int main() {
	unsigned code;
	cout << "Enter the code: ";
	cin >> code;

	switch (code) {
	case 1:
	case 2:
		cout << "South";
		break;
	case 3:
		cout << "North";
		break;
	case 4:
		cout << "Center-west";
		break;
	case 5:
	case 6:
		cout << "Northeast";
		break;
	case 7:
	case 8:
	case 9:
		cout << "Southeast";
		break;
	default:
		cout << "Invalid code";
		break;
	}
	cout << '\n';

	return 0;
}
