#include <iostream>

using namespace std;

int main()
{
	unsigned solutions[3] = { 0, 0, 0 };

	for (size_t f = 0; f <= 100; f++)
		if (f % 2)
			solutions[0] += f;
	cout << "For-loop solution: " << solutions[0] << '\n';

	unsigned w = 0;
	while (w <= 100)
	{
		if (w % 2)
			solutions[1] += w;
		w++;
	}
	cout << "While-loop solution: " << solutions[1] << '\n';

	unsigned d = 0;
	do
	{
		if (d % 2)
			solutions[2] += d;
		d++;
	} while (d < 100);
	cout << "Do-while-loop solution: " << solutions[2] << '\n';

	return 0;
}
