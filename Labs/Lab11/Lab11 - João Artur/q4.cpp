#include <iostream>

int main()
{
	using namespace std;

	char holidays[3][20] = { { '\0' }, { '\0' }, { '\0' } };
	const char myHoliday[] = "Christmas";

	cout << "What are your 3 favorite holidays?\n";

	for (size_t i = 0; i < 3; i++)
		cin.getline(holidays[i], 20);

	cout << holidays[0] << ", " <<
		holidays[1] << " and " <<
		holidays[2] << " are great holidays.\n";

	for (size_t i = 0; i < 3; i++)
	{
		bool teste = true;
		// 10 é o tamanho da variável myHoliday incluindo o \0.
		for (size_t j = 0; j < 10; j++)
			if (myHoliday[j] != holidays[i][j])
			{
				teste = false;
				break;
			}

		if (teste)
		{
			cout << myHoliday << " is also one of my favorites!\n";
			break;
		}
	}

	return 0;
}
