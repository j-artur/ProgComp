#include <iostream>
using namespace std;

int main()
{
	int pack = 20;

	int years;
	int cigarettes;
	float price;
	float total;

	cout << "For how many years have you been smoking? ";
	cin >> years;

	cout << "How many cigarettes do you smoke in one day? ";
	cin >> cigarettes;	

	cout << "What's the average price of a cigarette pack? ";
	cin >> price;	
	
	total = price * cigarettes / pack * years * 365;

	cout << "You've spent R$" << total << " in cigarettes" << endl;
}