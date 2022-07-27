#include <iostream>

using namespace std;

int main()
{
	char text[61] = { '\0' };
	size_t length = 0;

	cout << "Insert a phrase: \n";
	cin.getline(text, 60);

	for (size_t i = 0; text[i]; i++)
	{
		text[length] = text[i];
		if (text[i] != ' ')
			length++;
	}
	text[length] = '\0';

	cout << "No spaces: " << text << '\n';

	char invertedText[61] = { '\0' };
	for (size_t i = 0; i < length; i++)
		invertedText[i] = text[length - 1 - i];

	cout << "Inverted text: " << invertedText << '\n';

	if (!strcmp(text, invertedText))
		cout << "It's a palindrome!";
	else
		cout << "It's not a palindrome.";

	return 0;
}
