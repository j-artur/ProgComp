#include <iostream>

using namespace std;

struct ASCII
{
	short number;
	char character;
};

ASCII* newASCII(short, char);

int main()
{
	cout << "Insert the numeric code associated with a ASCII character and the character itself.\n";

	short num;
	cout << "Numeric code: ";
	cin >> num;

	char chr;
	cout << "Character: ";
	cin >> chr;

	ASCII* sym = newASCII(num, chr);

	cout << "\nNumeric code: " << sym->number;
	cout << "\nCharacter: " << sym->character;

	delete sym;
	return 0;
}

ASCII* newASCII(short n, char c)
{
	return new ASCII{ n, c };
}