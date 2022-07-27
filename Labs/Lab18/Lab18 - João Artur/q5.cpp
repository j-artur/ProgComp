#include <iostream>

using namespace std;

int main()
{
	unsigned ages[20] = { 0 };

	unsigned majorQty = 0;
	unsigned oldest = 0;
	unsigned youngest = 0xFFFF;

	unsigned i = 0;
	while (i < 20)
	{
		cin >> ages[i];

		if (!ages[i])
			break;

		if (ages[i] > 18)
			majorQty++;

		if (ages[i] > oldest)
			oldest = ages[i];

		if (ages[i] < youngest)
			youngest = ages[i];

		i++;
	}

	cout << "There are " << majorQty << " people older than 18 in the group.\n";

	cout << "The oldest one is " << oldest << "\ and the youngest is " << youngest << ".\n";

	return 0;
}
