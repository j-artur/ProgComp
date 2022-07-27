#include <iostream>

using namespace std;

struct Login
{
	char name[20];
	char password[20];
};

int main()
{
	Login admin = { "admin", "senha" };

	Login attempt = { '\0','\0' };
	cout << "Login:\n";

	cout << "User: ";
	cin >> attempt.name;

	for (size_t i = 0; i < 20; i++)
		if (admin.name[i] != attempt.name[i])
		{
			cout << "Wrong username\n";
			return 0;
		}

	cout << "Password: ";
	cin >> attempt.password;

	for (size_t i = 0; i < 20; i++)
		if (admin.password[i] != attempt.password[i])
		{
			cout << "Wrong password\n";
			return 0;
		}

	cout << "Login and password are correct.";

	return 0;
}

