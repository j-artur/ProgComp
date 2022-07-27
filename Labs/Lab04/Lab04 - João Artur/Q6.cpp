#include <iostream>
#include <cstdlib>
using namespace std;

void initialize(void);
void turnOn(void);
void verify(void);
void activate(void);

int main()
{
	initialize();
}

void initialize()
{
	cout << "Initializing system:\n";

	turnOn();
	verify();
	activate();
	
	int random = rand();

	if (random <= 16384) 
		cout << "Initialization failed.\n";
	else
	{
		cout << "Initialization succesful.\n";
		cout << "\nSystem is working.\n";
	}
}

void turnOn()
{
	cout << "- Turning on devices...\n";
}

void verify()
{
	cout << "- Verifying integrity...\n";
}

void activate()
{
	cout << "- Activating processes...\n";
}