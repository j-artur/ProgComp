#include <iostream>
#include <string>

using namespace std;

struct BankAccount
{
	int id = 0;
	string clientName;
	double balance = 0;
};

void showAccount(BankAccount);

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);

	BankAccount acc;

	cout << "Your account ID: ";
	cin >> acc.id;

	cout << "Your name: ";
	cin >> acc.clientName;

	showAccount(acc);

	double bal;
	cout << "How much do you want to deposit ?\nR$";
	cin >> bal;
	acc.balance += bal;

	showAccount(acc);

	return 0;
}

void showAccount(BankAccount acc)
{
	cout << '\n';
	cout << "Account #" << acc.id << '\n';
	cout << "Client Name: " << acc.clientName << '\n';
	cout << "Balance: R$" << acc.balance << '\n';
	cout << '\n';
}
