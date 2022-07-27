#include <iostream>

using namespace std;

int main()
{
	unsigned carsSpeed[10];

	cout << "The last 10 velocities registered:\n";
	for (size_t i = 0; i < 10; i++) cin >> carsSpeed[i];

	unsigned finesAccumulator = 0;
	unsigned finesCount = 0;

	for (size_t i = 0; i < 10; i++) {
		int overspeed = carsSpeed[i] - 80;

		if (overspeed > 0) {
			unsigned fine = overspeed * 8;
			cout << carsSpeed[i] << " Km/h exceeds the limit = fine of R$" << fine << '\n';
			finesAccumulator += fine;
			finesCount++;
		}
	}

	cout << '\n' << finesCount << " cars were fined for a total value of R$" << finesAccumulator << ".\n";

	return 0;
}