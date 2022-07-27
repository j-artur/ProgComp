#include <iostream>
#include <fstream>

using namespace std;

struct Pair { int x; int y; };

ostream& operator<<(ostream&, Pair&);

int main() {
	const auto file = "q3.txt";

	ifstream fin;
	fin.open(file);
	if (!fin.is_open()) cout << "Couldn't open file";
	else {
		cout << "Pairs: ";
		while (fin.good()) {
			Pair pair;
			fin >> pair.x >> pair.y;
			cout << pair << ' ';
		}
		fin.close();
	}

	return 0;
}

ostream& operator<<(ostream& os, Pair& pair) { return os << '[' << pair.x << ',' << pair.y << ']'; }
