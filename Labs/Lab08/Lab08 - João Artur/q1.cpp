#include <iostream>

void bhaskara(double, double, double);

int main()
{
	using namespace std;

	cout << "Insert the coeficients a, b and c for a quadratic equation.\n";

	cout << "a: ";
	double a;
	cin >> a;

	cout << "b: ";
	double b;
	cin >> b;

	cout << "c: ";
	double c;
	cin >> c;

	bhaskara(a, b, c);
}

void bhaskara(double a, double b, double c)
{
	double discriminant = pow(b, 2) - 4 * a * c;

	if (discriminant < 0)
	{
		std::cout << "There's no real root, roots are complex conjugates.";
		return;
	}

	if (discriminant == 0)
	{
		double x = -b / (2 * a);

		std::cout << "The root of the equation is " << x;
		return;
	}

	if (discriminant > 0)
	{
		double x1 = (-b + sqrt(discriminant)) / (2 * a);
		double x2 = (-b - sqrt(discriminant)) / (2 * a);

		std::cout << "The roots of the equation are " << x1 << " and " << x2;
	}
}