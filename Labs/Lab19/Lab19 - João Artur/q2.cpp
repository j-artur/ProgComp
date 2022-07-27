#include <iostream>

using namespace std;

const char* ordinal(size_t);
unsigned sum(unsigned*, size_t);

int main()
{
	const char* months[12] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};

	unsigned sales[3][12];
	unsigned salesTotal[3];

	for (size_t i = 0; i < 3; i++)
	{
		cout << "Insert the number of sold books on the " << ordinal(i) << " year: \n";
		for (size_t j = 0; j < 12; j++)
		{
			cout << months[j] << ": ";
			cin >> sales[i][j];
		}
		cout << '\n';
	}

	cout << "Total sales\n";
	for (size_t i = 0; i < 3; i++)
	{
		salesTotal[i] = sum(sales[i], 12);
		cout << ordinal(i) << " year: " << salesTotal[i] << '\n';
	}
	cout << '\n';

	cout << "On the three years " << sum(salesTotal, 3) << " books were sold.\n";

	return 0;
}

const char* ordinal(size_t n)
{
	return n == 0 ? "1st" : n == 1 ? "2nd" : "3rd";
}

unsigned sum(unsigned* group, size_t size)
{
	unsigned sum = 0;

	for (size_t i = 0; i < size; i++)
		sum += group[i];

	return sum;
}