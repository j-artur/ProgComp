#include <iostream>
#include <string>

using namespace std;

struct Product {
	char letter = '\0';
	string name;
	int price = 0;
};

struct Purchase {
	Product* product;
	float order = 0;
	int total = 0;
};

string priceStr(int);
void addToCart(Purchase*, Product, float);
void showCart(Purchase*);

int main() {
	Product products[3] = {
		{ 'a', "Lettuce", 125 },
		{ 'b', "Beetroot", 65 },
		{ 'c', "Carrot", 90 }
	};

	cout << "Supermarket ABC\n";
	cout << "---------------\n";

	for (auto product : products) {
		cout << product.letter << ") ";
		cout.width(16); cout << left << product.name;
		cout.width(16); cout << left << priceStr(product.price);
		cout << endl;
	}

	Purchase cart[3] = {
		{ &products[0] },
		{ &products[1] },
		{ &products[2] },
	};

	char input;
	do {
		cout << "Order pressing the letters (a, b, c) and (x) to exit: ";
		cin >> input;

		Product selected;

		switch (input) {
		case 'a':
			selected = products[0];
			break;
		case 'b':
			selected = products[1];
			break;
		case 'c':
			selected = products[2];
			break;
		default:
			continue;
		}

		float amount;
		cout << "Select how much of " << selected.name << " in kilograms: ";
		cin >> amount;

		addToCart(cart, selected, amount);

		showCart(cart);
	} while (input != 'x');

	system("cls");

	showCart(cart);

	int ordersTotal = 0;
	float totalWeight = 0;
	for (auto purchase : cart) {
		ordersTotal += purchase.total;
		totalWeight += purchase.order;
	};

	int discount = ordersTotal > 10000 ? int(.05f * ordersTotal) : 0;

	int fee;
	if (totalWeight < 5) fee = 350;
	else if (totalWeight < 20) fee = 1000;
	else fee = 8 + 10 * totalWeight;

	cout.width(42); cout << left << "Total for orders:" << priceStr(ordersTotal) << '\n';
	cout.width(42); cout << left << "Discounts:" << priceStr(discount) << '\n';
	cout.width(42); cout << left << "Shipping fee:" << priceStr(fee) << '\n';
	cout << "------------------------------------------------------\n";
	cout.width(42); cout << left << "Total to pay:" << priceStr(ordersTotal - discount + fee) << '\n';

	return 0;
}

string priceStr(int price) {
	string reais = to_string(int(price / 100));
	string cents = to_string(price % 100);

	return "R$ " + reais + ',' + cents;
}

void addToCart(Purchase* cart, Product item, float amount) {
	Purchase* purchase;

	switch (item.letter) {
	case 'a':
		purchase = &cart[0];
		break;
	case 'b':
		purchase = &cart[1];
		break;
	case 'c':
		purchase = &cart[2];
		break;
	default:
		return;
	}

	purchase->order += amount;
	purchase->total += int(amount * item.price);

	return;
}

void showCart(Purchase* cart) {
	cout.width(14); cout << left << "Product";
	cout.width(14); cout << left << "Price/Kg";
	cout.width(14); cout << left << "Order (Kg)";
	cout.width(14); cout << left << "Subtotal";
	cout << endl;

	cout << "------------  ------------  ------------  ------------\n";

	for (size_t i = 0; i < 3; i++) {
		auto purchase = cart[i];
		if (purchase.order) {
			cout.width(14); cout << left << purchase.product->name;
			cout.width(14); cout << left << priceStr(purchase.product->price);
			cout.width(14); cout << left << to_string(purchase.order) + "Kg";
			cout.width(14); cout << left << priceStr(purchase.total);
			cout << endl;
		}
	}

	cout << "------------------------------------------------------\n";
}