#include <iostream>
using namespace std;

int main()
{
	float volume, area, height, width, length;

	cout << "Width: ";
	cin >> width;

	cout << "Length: ";
	cin >> length;

	area = width * length;
	cout << "Base area = " << area << endl;

	cout << "Height: ";
	cin >> height;

	volume = area * height;
	cout << "Prism volume = " << volume << endl;
}