#include <iostream>

int main()
{
	using namespace std;

	const int pwSize = 9;

	char senha[pwSize] = "ProgComp";

	char tentativa[pwSize];
	cout << "Type the password (8 characters): ";
	cin >> tentativa;

	bool teste = true;
	for (size_t i = 0; i < pwSize; i++)
		if (senha[i] != tentativa[i])
		{
			teste = false;
			break;
		}

	if (teste)
		cout << "\nYou got it right.\n";
	else
		cout << "\nWrong password.\n";

	return 0;
}
