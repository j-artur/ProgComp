#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned int uint;

void unit(ifstream&, int, uint = 10);

int main() {
	ifstream fin;
	fin.open("stats.txt");

	unit(fin, 1);
	unit(fin, 2);
	unit(fin, 3);

	fin.close();

	return 0;
}

void unit(ifstream& fin, int unit, uint lines) {
	int revision = 0;
	int fixation = 0;
	int learning = 0;

	for (uint i = 0; i < lines; i++) {
		int lab, rev, fix, lrn;

		fin >> lab >> rev >> fix >> lrn;

		revision += rev;
		fixation += fix;
		learning += lrn;
	}

	cout << "-------------" << endl;
	cout << "Unit " << unit << endl;
	cout << "-------------" << endl;
	cout << "Revision: " << revision << endl;
	cout << "Fixation: " << fixation << endl;
	cout << "Learning: " << learning << endl;
	cout << "-------------" << endl;
	cout << "Total: " << revision + fixation + learning << endl;
	cout << endl;
}
