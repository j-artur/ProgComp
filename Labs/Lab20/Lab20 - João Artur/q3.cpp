#include <iostream>

using namespace std;

int main()
{
	cout << "Enter a text (# to finish):\n";
	char line[100];

	unsigned substitutions = 0;
	bool reading = true;
	while (reading)
	{
		cin.getline(line, 100);

		char formattedLine[101] = { '\0' };
		for (size_t i = 0, j = 0; j < 100; i++) {
			if (line[i] == '#') {
				formattedLine[j] = '\0';
				reading = false;
				break;
			}

			if (line[i] == '.') {
				formattedLine[j] = '!';
				substitutions++;
			}
			else {
				formattedLine[j] = line[i];

				if (line[i] == '!') {
					formattedLine[++j] = '!';
					substitutions++;
				}
			}
			j++;
		}
		cout << formattedLine << '\n';
	}
	cout << "\nSubstitutions: " << substitutions << '\n';

	return 0;
}