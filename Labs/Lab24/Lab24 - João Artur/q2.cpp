#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct Soldier {
	char name[20];
	int kills = 0;
	int deaths = 0;
	float kda = 1;
	int matches = 0;
};

Soldier newSoldier();
void showSoldier(Soldier*);
void updateSoldier(Soldier*);

int main() {
	const auto filepath = "q2.dat";

	Soldier soldier;

	ifstream fin;
	fin.open(filepath, ios_base::in | ios_base::binary);
	if (fin.is_open()) {
		fin.read((char*)(&soldier), sizeof(Soldier));
	}
	else {
		soldier = newSoldier();
	}
	fin.close();

	auto running = true;
	while (running) {
		cout << "[N]ew soldier (overwrite last one)" << endl;
		cout << "[U]pdate soldier (with data from last match)" << endl;
		cout << "[S]how soldier (current one)" << endl;
		cout << "[E]xit" << endl;

		char cmd;
	input:
		cin >> cmd;

		cout << endl;

		switch (char(toupper(cmd))) {
		case 'N': {
			soldier = newSoldier();
			break;
		}
		case 'U': {
			updateSoldier(&soldier);
			break;
		}
		case 'S': {
			showSoldier(&soldier);
			break;
		}
		case 'E': {
			running = false;
			break;
		}
		default: {
			cout << "Invalid option" << endl;
			goto input;
			break;
		}
		}
	}

	ofstream fout;
	fout.open(filepath, ios_base::out | ios_base::binary);
	fout.write((char*)(&soldier), sizeof(Soldier));
	fout.close();

	return 0;
}

Soldier newSoldier() {
	Soldier soldier;

	cout << "Soldier name: ";
	cin >> soldier.name;

	cout << "Number of kills: ";
	cin >> soldier.kills;

	cout << "Number of deaths: ";
	cin >> soldier.deaths;

	soldier.kda = soldier.deaths ? float(soldier.kills) / float(soldier.deaths) : soldier.kills;

	cout << "Number of played matches: ";
	cin >> soldier.matches;

	cout << endl;

	return soldier;
}

void showSoldier(Soldier* soldier) {
	cout << "Soldier " << soldier->name << endl;
	cout << "Kills: " << soldier->kills << endl;
	cout << "Deaths: " << soldier->deaths << endl;
	cout << "Kill/Death Ratio: " << soldier->kda << endl;
	cout << "Matches: " << soldier->matches << endl;
	cout << endl;
}

void updateSoldier(Soldier* soldier) {
	int kills;
	int deaths;

	cout << "Kills: ";
	cin >> kills;

	cout << "Deaths: ";
	cin >> deaths;

	soldier->kills += kills;
	soldier->deaths += deaths;
	soldier->kda = soldier->deaths ? float(soldier->kills) / float(soldier->deaths) : soldier->kills;
	soldier->matches++;

	cout << endl;
}
