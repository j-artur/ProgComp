#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string file;
	cout << "File: ";
	cin >> file;

	ifstream fin;

	fin.open(file);
	if (!fin.is_open()) {
		cout << "Read failure.";
		exit(1);
	}

	string word;

	size_t count = 0;
	while (fin >> word) {
		string* invertedWord = new string(word);

		auto length = word.length();

		for (size_t i = 0; i < length; i++) {
			word[i] = char(tolower(word[i]));

			(*invertedWord)[length - 1 - i] = word[i];
		}

		if (word == *invertedWord) {
			cout << word << '\n';
			count++;
		}

		delete invertedWord;
	}

	fin.close();

	cout << count << " palindromes were found on this file.\n";

	return 0;
}
