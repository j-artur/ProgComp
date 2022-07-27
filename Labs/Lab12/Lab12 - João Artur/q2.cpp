#include <iostream>
#include <string>
#include <locale>

using namespace std;

struct Word
{
	char en[20];
	char pt[20];
	char es[20];
};

void showWord(Word);

int main()
{
	locale::global(locale({ "pt-BR" }));

	Word dictionary[10] =
	{
		{ "breakfast", "café da manhã", "desayuno" },
		{ "shopping", "mall", "centro comercial" }
	};

	cout << "Enter a word in three languages.\n";

	cout << "English: ";
	cin >> dictionary[2].en;
	cout << "Português: ";
	cin >> dictionary[2].pt;
	cout << "Español: ";
	cin >> dictionary[2].es;

	cout << '\n';

	cout << left; cout.width(4); cout << "N.";
	cout << left; cout.width(20); cout << "English";
	cout << left; cout.width(20); cout << "Português";
	cout << left; cout.width(20); cout << "Español";
	cout << '\n';

	for (size_t i = 0; i < 10; i++)
	{
		cout << '#';
		cout << left; cout.width(3); cout << i + 1;
		showWord(dictionary[i]);
	}

	return 0;
}

void showWord(Word word)
{
	cout << left; cout.width(20); cout << word.en;
	cout << left; cout.width(20); cout << word.pt;
	cout << left; cout.width(20); cout << word.es;
	cout << '\n';
}
