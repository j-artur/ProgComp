#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	if (argc > 1) {
		system(argv[1]);
		cout << "Executando " << argv[1] << "..." << endl;
	}
	else
		cout << "Passe um argumento!" << endl;
}