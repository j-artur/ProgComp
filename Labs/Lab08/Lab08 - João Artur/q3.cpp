#include <iostream>

using namespace std;

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(8);

	cout << 3333.3f << '\n';
	cout << 2049.9f << '\n';
	cout << 125.49f << '\n';
	cout << 13.6f << '\n';
	cout << 13.37f << '\n';
}