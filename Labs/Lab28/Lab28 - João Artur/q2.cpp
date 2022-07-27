#include <iostream>

using namespace std;

struct Tuple {
	int a;
	int b;
	int c;
};

void change(Tuple&, Tuple&);

int main() {
	Tuple a = { 15, 20, 25 };
	Tuple b = { 40 , 50, 60 };

	cout << "Tuple A: " << a.a << ' ' << a.b << ' ' << a.c << endl;
	cout << "Tuple B: " << b.a << ' ' << b.b << ' ' << b.c << endl;

	cout << endl << "Inverting..." << endl;
	change(a, b);

	cout << "Tuple A: " << a.a << ' ' << a.b << ' ' << a.c << endl;
	cout << "Tuple B: " << b.a << ' ' << b.b << ' ' << b.c << endl;

	return 0;
}

void change(Tuple& tupleA, Tuple& tupleB) {
	Tuple temp = tupleA;
	tupleA = tupleB;
	tupleB = temp;
}
