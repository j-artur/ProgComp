#include <iostream>
#include <fstream>

using namespace std;

union Password {
	char alphanum[16];
	int numeric;
};

int main() {
	const auto filepath = "q3.dat";

	cout << "[0] - Show password" << endl;
	cout << "[1] - Store new password" << endl;

	int pwType;
	Password password;

	char input;
	cin >> input;

	switch (input) {
	case '0': {
		ifstream fin;
		fin.open(filepath, ios_base::in | ios_base::binary);
		if (fin.is_open()) {
			fin.read((char*)(&pwType), sizeof(pwType));
			switch (pwType) {
			case 1:
				fin.read((char*)(&password.alphanum), sizeof(password.alphanum));
				cout << "alphanumeric password: " << password.alphanum << endl;
				break;
			case 2:
				fin.read((char*)(&password.numeric), sizeof(password.numeric));
				cout << "numeric password: " << password.numeric << endl;
				break;
			}
		}
		else {
			cout << "No file found." << endl;
		}
		fin.close();
		break;
	}
	case '1': {
		cout << "Type:" << endl;
		cout << "[1] - Alphanumeric" << endl;
		cout << "[2] - Numeric" << endl;
		cin >> pwType;

		ofstream fout;
		fout.open(filepath, ios_base::out, ios_base::binary);
		fout.write((char*)(&pwType), sizeof(pwType));
		switch (pwType) {
		case 1:
			cout << "alphanumeric password: ";
			cin >> password.alphanum;
			fout.write((char*)(&password.alphanum), sizeof(password.alphanum));
			break;
		case 2:
			cout << "numeric password: ";
			cin >> password.numeric;
			fout.write((char*)(&password.numeric), sizeof(password.numeric));
			break;
		}
		fout.close();
		break;
	}
	default:
		break;
	}

	return 0;
}
