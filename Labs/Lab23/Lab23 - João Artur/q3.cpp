#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
	string firstName;
	string lastName;
	char shift;
	unsigned grade;
};

int main() {
	ifstream fin;

	fin.open("interclass.txt");
	if (!fin.is_open()) {
		cout << "Read failure.";
		exit(1);
	}

	Student students[12];

	for (size_t i = 0; i < 12; i++) {
		fin >> students[i].firstName;
		fin >> students[i].lastName;
		fin >> students[i].shift;
		fin >> students[i].grade;
	}


	fin.close();

	char shifts[] = { 'M', 'T' };
	unsigned grades[] = { 6, 7, 8 };

	for (auto shift : shifts) {
		for (auto grade : grades) {
			auto title = string(shift == 'M' ? "Morning" : "Afternoon") + ' ' + to_string(grade) + "nd Grade";

			cout << title << '\n';

			for (auto ch : title) cout << '-';
			cout << '\n';

			for (auto student : students) {
				if (student.shift == shift && student.grade == grade) {
					cout << student.firstName + ' ' + student.lastName + ' ' + student.shift + to_string(student.grade) + '\n';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
/*
* a) Não. O arquivo textual não apresenta informações sobre o sexo dos alunos.
*
* b) Uma das formas seria acrescentar (M) ou (F) após o nome de cada aluno para representar seu sexo
* e adicionar outro campo no struct para colher essa informação.
*/
