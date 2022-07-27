#include <iostream>
#include "game.h"

using namespace std;

// Escolhe e retorna os atributos a serem comparados
short* selectAttributes(Card& cardA, Card& cardB) {
	cout << "Card: " << cardA.name << endl;
	cout << "1. HP" << endl;
	cout << "2. Attack" << endl;
	cout << "3. Defense" << endl;
	cout << "4. Special Attack" << endl;
	cout << "5. Special Defense" << endl;
	cout << "6. Speed" << endl;

	char input;

// Label para usar GO-TO
input:
	cout << endl;
	cout << "Choose an attribute: ";
	cin >> input;
	cout << endl;

	// Retorna um vetor dinâmico com o valor dos atributos escolhidos
	switch (input) {
	case '1':
		return new short[2]{ cardA.hp, cardB.hp };
	case '2':
		return new short[2]{ cardA.attack, cardB.attack };
	case '3':
		return new short[2]{ cardA.defense, cardB.defense };
	case '4':
		return new short[2]{ cardA.specialAttack, cardB.specialAttack };
	case '5':
		return new short[2]{ cardA.specialDefense, cardB.specialDefense };
	case '6':
		return new short[2]{ cardA.speed, cardB.speed };
	default:
		cout << "\x1B[91m" << "Invalid option" << "\033[0m" << endl;

		// Volta para o input caso a opção escolhida seja inválida
		goto input;
	}
}

void showScoreboard(Player* players) {
	cout << "Scoreboard: " << players[0].name << ' ' << players[0].points;
	cout << " x " << players[1].points << ' ' << players[1].name << endl;
	cout << "----------------------------" << endl << endl;
}
