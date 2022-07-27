#include <iostream>
#include <fstream>

using namespace std;

inline void print(int i) { cout << "\033[33m" << i << "\033[0m"; }
inline void print(double f) { cout << "\033[94m" << f << "\033[0m"; }
inline void print(const char* str) { cout << "\033[31m" << str << "\033[0m"; }

int main() {
	cout << "Integer: ";
	print(45);
	cout << "\nFloating-point: ";
	print(3.9);
	cout << "\nString: ";
	print("Hello World");
	cout << "\n";

	return 0;
}
