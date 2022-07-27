#include <iostream>

union Player
{
	char name[25];
	int number;
};

struct Goal
{
	Player player;
	int hour;
	int min;
};

int main()
{
	using namespace std;

	Goal goals[3] = { 0 };

	cout << "Insert the data from the 3 last goas:\n";
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Goal:\n";
		if (i % 2 == 0)
		{
			cout << "Name: ";
			cin >> goals[i].player.name;
		}
		else
		{
			cout << "Number: ";
			cin >> goals[i].player.number;
		}

		cout << "Time: ";
		cin >> goals[i].hour;
		cin.ignore();
		cin >> goals[i].min;
	}
	cout << '\n';
}