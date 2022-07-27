#include <iostream>
#include <string>

using namespace std;

int main()
{
	string text;
	cout << "Insert a text: \n";
	getline(cin, text);

	for (size_t i = 0; text[i] != '@'; i++)
		cout << text[i];
	cout << '\n';

	return 0;
}
