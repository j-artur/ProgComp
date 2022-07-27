#include <iostream>
#include <fstream>
#include <cctype>
#include <stdlib.h>
#include <ctime>
#include "game.h"

using namespace std;

int main() {
	// Faz a seed para o RNG baseada na hora em que o programa começa a ser executado
	srand(time(0));

	// Arquivo binário que guarda as informações do baralho
	const auto file = "../deck.dat";

	// Parte do cabeçalho do arquivo
	char header[4] = { 'D', 'E', 'C', 'K' };

	unsigned short deckLength;

	ifstream fin;
	// Bloco de try catch para certificar que o arquivo binário é válido
	try {
		// Se não conseguir abrir o arquivo, joga um erro
		fin.open(file, ios_base::in | ios_base::binary);
		if (!fin.is_open()) {
			throw "Couldn't open file";
		}

		// Se o cabeçalho estiver incorreto, joga um erro
		char test[4];
		fin.read(test, sizeof(header));
		for (unsigned i = 0; i < 4; i++) {
			if (header[i] != test[i]) {
				throw "Invalid file header";
			}
		}

		fin.read((char*)(&deckLength), sizeof(deckLength));
		if (deckLength < 8) {
			throw "Not enough cards";
		}
	} catch (const char* msg) {
		// Imprime uma mensagem de erro
		cout << "\x1B[91m";
		cout << "Invalid deck file. Reason: " << endl;
		cout << msg;
		cout << "\033[0m" << endl;
		cout << endl;

		// Encerra o programa
		return EXIT_FAILURE;
	}

	// Lê as carta do arquivo e guarda num vetor dinâmico
	auto* deck = new Card[deckLength];
	fin.read((char*)deck, sizeof(Card) * (long long)deckLength);
	fin.close();

	cout << "Pokemon Top Trumps" << endl;
	cout << "------------------" << endl;

	while (true) {
		// Recebe o input para começar uma partida ou encerrar o programa
		char input;
		cout << "Start new game? [Y/N] ";
		cin >> input;

		// Vetor para dois jogadores
		Player players[2];

		switch (toupper(input)) {
		case 'Y': {
			// Loop para atribuir nome aos jogadores e distribuir as cartas
			for (unsigned i = 0; i < 2; i++) {
				cout << "Player " << i + 1 << ": ";
				cin >> players[i].name;

				for (auto& card : players[i].cards) {
					// rand() % X devolve um número pseudoaleatório entre 0 e X-1
					card = &(deck[rand() % deckLength]);
				}
			}
			cout << "----------------" << endl;
			cout << endl;

			// Loop para executar as 4 rodadas
			for (unsigned i = 0; i < 4; i++) {
				// Alterna o jogador que escolhe de cada rodada
				auto& playerA = players[i % 2];
				auto& playerB = players[(i + 1) % 2];

				cout << '[' << playerA.name << ']' << endl;
				cout << endl;

				// Referências para as cartas da rodada
				auto& cardA = *(playerA.cards[i]);
				auto& cardB = *(playerB.cards[i]);

				// Recebe os dois atributos a serem comparados em um vetor dinâmico
				auto attributes = selectAttributes(cardA, cardB);
				auto& attrA = attributes[0];
				auto& attrB = attributes[1];

				cout << '[' << playerA.name << "] ";
				cout.width(11); cout << left << cardA.name;
				cout << " | " << attrA << endl;

				cout << '[' << playerB.name << "] ";
				cout.width(11); cout << left << cardB.name;
				cout << " | " << attrB << endl;

				cout << endl;

				// Atribuir os pontos com base no resultado da comparação entre os atributos
				if (attrA > attrB) {
					playerA.points += 2;
				} else if (attrA < attrB) {
					playerB.points += 2;
				} else {
					playerA.points++;
					playerB.points++;
				}

				delete[] attributes;

				showScoreboard(players);
			}
				break;
		}
		case 'N': {
			delete[] deck;

			cout << "Exiting..." << endl;

			return EXIT_SUCCESS;
		}
		default : {
			cout << "\x1B[91m" << "Invalid option" << "\033[0m" << endl;

			continue;
		}
		}
	}
}
