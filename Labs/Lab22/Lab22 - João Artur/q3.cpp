#include <iostream>
#include <string>

using namespace std;

struct Plate {
	string name;
	int price;
};

string priceStr(int);

int main() {
	Plate menu[4] = {
		{ "Pizza", 2750 },
		{ "Hamburger", 1600 },
		{ "Milkshake", 1300 },
		{ "Ice cream", 500 }
	};

	cout << "Menu:\n";
	cout.width(8); cout << left << "Number";
	cout.width(16); cout << left << "Item";
	cout.width(16); cout << left << "Price";
	cout << '\n';
	for (size_t i = 0; i < 4; i++) {
		const auto item = menu[i];
		cout.width(8); cout << left << "#" + to_string(i + 1);
		cout.width(16); cout << left << item.name;
		cout.width(16); cout << left << priceStr(item.price);
		cout << '\n';
	}

	int total = 0;

	unsigned input;
	while (true) {
		cout << "Order by number: ";
		cin >> input;

		if (input == 0) break;

		Plate selected = menu[input - 1];

		cout << "Added 1 " << selected.name << " to your order.\n";

		total += selected.price;
	};

	cout << "Your final total: " << priceStr(total) << '\n';

	return 0;
}

string priceStr(int price) {
	string reais = to_string(int(price / 100));
	string cents = to_string(price % 100);

	return "R$ " + reais + ',' + cents;
}
