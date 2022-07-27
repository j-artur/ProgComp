#include <iostream>
#include <string>

using namespace std;

int main() {
	string text;
	cout << "Enter a text (@ to finish):\n";
	getline(cin, text);

	unsigned vowels[5] = { 0 };

	try {
		for (char letter : text) {
			switch (letter) {
			case 'a':
			case 'A':
				vowels[0]++;
				break;
			case 'e':
			case 'E':
				vowels[1]++;
				break;
			case 'i':
			case 'I':
				vowels[2]++;
				break;
			case 'o':
			case 'O':
				vowels[3]++;
				break;
			case 'u':
			case 'U':
				vowels[4]++;
				break;
			case '@':
				throw false;
			default:
				break;
			}
		}
	}
	catch (const bool) {}

	cout << "\na: " << vowels[0];
	cout << "\ne: " << vowels[1];
	cout << "\ni: " << vowels[2];
	cout << "\no: " << vowels[3];
	cout << "\nu: " << vowels[4];
	cout << '\n';

	return 0;
}
