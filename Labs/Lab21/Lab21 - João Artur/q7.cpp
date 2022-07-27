#include <iostream>
#include <string>

using namespace std;

struct Swimmer {
	string name;
	unsigned age;
	string category;
};

string determineCategory(unsigned);

int main() {
	Swimmer swimmer;

	cout << "Swimmer's name: ";
	cin >> swimmer.name;

	cout << swimmer.name << "'s age: ";
	cin >> swimmer.age;

	swimmer.category = determineCategory(swimmer.age);

	cout << swimmer.name << '\n' << swimmer.age << '\n' << swimmer.category << '\n';

	return 0;
}

string determineCategory(unsigned age) {
	if (age > 5 && age <= 7) return "infantile";
	if (age >= 8 && age <= 10) return "juvenile";
	if (age >= 11 && age <= 15) return "teenager";
	if (age > 15 && age <= 30) return "adult";
	if (age > 30) return "senior";
	return "invalid";
}