#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	if (argc == 4)
		cout << "Estou aprendendo " << argv[3] << '/' << argv[1] << '!' << endl;
	else
		cout << "Passe 3 argumentos!" << endl;
}