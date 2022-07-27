#include <iostream>

using namespace std;

struct Person
{
	char name[20];
	unsigned age;
	bool sex;
};

int main()
{
	float age = 0;

	Person person;
	unsigned count = 0;
	while (true)
	{
		cout << "Name: ";
		cin >> person.name;

		if (strcmp(person.name, "fim") == 0)
			break;

		cout << "Age: ";
		cin >> person.age;
		cout << "Sex (F:0 M:1): ";
		cin >> person.sex;

		age += person.age;
		count++;
	}

	age /= count;

	cout << "The average age in the group is " << age;

	return 0;
}
