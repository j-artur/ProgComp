#include <iostream>

using namespace std;

float lapTime(float);

int main() {
	float time;
	while (true) {
		cout << "Lap: ";
		if (cin >> time) {
			float total = lapTime(time);
			cout << "Total time: " << total << endl;
		}
		else break;
	}

	return 0;
}

float lapTime(float time) {
	static float accumulator = 0;

	accumulator += time;

	return accumulator;
}
