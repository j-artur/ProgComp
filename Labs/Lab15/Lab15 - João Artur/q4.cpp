#include <iostream>
#include <string>

using namespace std;

struct Place {
	char name[20];
	char country[20];
	char continent[20];
};

Place getPlace();

int main()
{
	int size = 0;
	cout << "How many places do you want to visit on your next vacation? ";
	cin >> size;
	cin.ignore(1);

	Place* places = new Place[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Place #" << i + 1 << "\n";
		places[i] = getPlace();
		cout << '\n';
	}

	cout.width(20); cout << left; cout << "Place";
	cout.width(20); cout << left; cout << "Country";
	cout.width(20); cout << left; cout << "Continent";
	cout << '\n';
	for (size_t i = 0; i < size; i++)
	{
		cout.width(20); cout << left; cout << places[i].name;
		cout.width(20); cout << left; cout << places[i].country;
		cout.width(20); cout << left; cout << places[i].continent;
		cout << '\n';
	}

	delete[] places;

	return 0;
}

Place getPlace()
{
	Place place;

	cout << "Name: ";
	cin.getline(place.name, 20);

	cout << "Country: ";
	cin.getline(place.country, 20);

	cout << "Continent: ";
	cin.getline(place.continent, 20);

	return place;
}