#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string file;
	cout << "Enter the file to be copied: ";
	cin >> file;

	size_t pos = file.find_last_of('.');
	string fileName = file.substr(0, pos);
	string fileExtension = file.substr(pos);
	string newFile = fileName + "_m" + fileExtension;

	ifstream fin;

	fin.open(file);
	if (!fin.is_open()) {
		cout << "Read failure.";
		exit(1);
	}

	string filecontent;
	string temp;

	filecontent += "// " + newFile + '\n';
	filecontent += "#define print cout\n";

	while (fin.good()) {
		getline(fin, temp);

		size_t t = temp.find("cout");
		if (t != string::npos) {
			string startOfLine = temp.substr(0, t);
			string restOfLine = temp.substr(t + 4);
			temp = startOfLine + "print" + restOfLine;
		}

		filecontent += temp + '\n';
	}

	fin.close();

	ofstream fout;

	fout.open(newFile);

	fout << filecontent;

	fout.close();

	return 0;
}
