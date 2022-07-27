#include <iostream>

using namespace std;

int main()
{
	char ascii[16][16];

	for (size_t i = 0; i < 16; i++)
		for (size_t j = 0; j < 16; j++)
			ascii[j][i] = char(16 * i + j);

	cout << "Insert the coordinates of your region on interest\n";

	unsigned from[2] = { 0, 15 };
	unsigned initialRow;
	unsigned initialCol;
	cout << "From: ";
	cin.ignore();
	cin >> initialRow;
	cin.ignore();
	cin >> initialCol;
	cin.ignore();

	cin.ignore();

	unsigned to[2] = { 0, 15 };
	unsigned finalRow;
	unsigned finalCol;
	cout << "To: ";
	cin.ignore();
	cin >> finalRow;
	cin.ignore();
	cin >> finalCol;
	cin.ignore();

	unsigned height = finalRow - initialRow + 1;
	unsigned length = finalCol - initialCol + 1;

	char** matrix = new char* [height];
	for (size_t i = 0; i < height; i++)
		matrix[i] = new char[length];

	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < length; j++)
			matrix[i][j] = ascii[i + initialRow][j + initialCol];

	cout << '\n';

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < length; j++)
			cout << matrix[i][j] << ' ';
		cout << '\n';
	}

	for (size_t i = 0; i < height; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}
