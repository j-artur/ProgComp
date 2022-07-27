#include <iostream>
#include <fstream>
#include <cctype>
#include "generator.h"

using namespace std;

// Variáveis declaradas globalmente para serem usadas nas funções do outro arquivo

// Vetor que guarda todas as cartas do baralho
Card deck[32];
// Variável que mostra a quantidade de cartas válidas no baralho
unsigned short deckLength = 0;

int main() {
	// Arquivo binário que guarda as informações do baralho
	const auto file = "../deck.dat";

	// Parte do cabeçalho do arquivo
	char header[4] = { 'D', 'E', 'C', 'K' };

	ifstream fin;
	// Bloco de try catch para certificar que o arquivo binário está correto
	try {
		// Se não conseguir abrir o arquivo, joga um erro
		fin.open(file, ios_base::in | ios_base::binary);
		if (!fin.is_open()) {
			throw "File couldn't be open. Maybe doesn't exist.";
		}

		// Se o cabeçalho estiver incorreto, joga um erro
		char test[4];
		fin.read(test, sizeof(header));
		for (unsigned i = 0; i < 4; i++) {
			if (header[i] != test[i]) {
				throw "Invalid file header.";
			}
		}
		fin.read((char*)(&deckLength), sizeof(deckLength));
		if (deckLength > 32) {
			throw "Invalid file header.";
		}

		// Lê todas as cartas e salva no vetor
		for (unsigned i = 0; i < deckLength; i++) {
			fin.read((char*)&(deck[i]), sizeof(Card));
		}
	} catch (const char* msg) {
		// Imprime uma mensagem de erro
		cout << "\x1B[91m";
		cout << "Invalid deck file. Reason: " << endl;
		cout << msg;
		cout << "\033[0m";
		cout << endl << endl;
	}

	// Fecha o arquivo se estiver aberto
	fin.close();

	printHeader("Cards Generator");

	// Loop infinito para o usuário executar quantas ações quiser até escolher sair
	while (true) {
		cout << endl;
		cout << "(R)egister" << endl;
		cout << "(I)mport" << endl;
		cout << "(U)pdate" << endl;
		cout << "(D)elete" << endl;
		cout << "(L)ist" << endl;
		cout << "(S)ave and exit" << endl;
		cout << "(E)xit without saving" << endl;
		cout << endl;

		// Pede uma ação ao usuário
		char input;
		cout << "Choose an option: ";
		cin >> input;
		cout << endl;

		// Switch executa a ação especificada pelo usuário
		// Os cases usam blocos para evitar conflitos de variáveis
		switch ((char)toupper(input)) {
			case 'R': {
				printHeader("Register Card");

				// Pede a entrada de dados da carta para o usuário
				auto card = inputCard();

				addCard(card);

				break;
			}
			case 'I': {
				printHeader("Import Cards");

				// Pede o caminho de um arquivo ao usuário
				char file[60];
				cout << "File: ";
				cin >> file;

				importCards(file);

				break;
			}
			case 'U': {
				printHeader("Update Card");

				listCards();

				unsigned number;
				cout << "Card number: ";
				cin >> number;

				// Edita a carta escolhida
				updateCard(number - 1);

				break;
			}
			case 'D': {
				printHeader("Delete Card");

				listCards();

				unsigned number;
				cout << "Card number: ";
				cin >> number;

				deleteCard(number - 1);

				break;
			}
			case 'L': {
				printHeader("List Deck");

				// Lista as cartas com seus atributos
				listDeck();

				break;
			}
			case 'S': {
				ofstream fout;

				// Abre ou cria o arquivo binário
				fout.open(file, ios_base::out | ios_base::binary);

				// Salva o cabeçalho do arquivo contendo a palavra DECK e o número de cartas
				fout.write(header, sizeof(header));
				fout.write((char*)(&deckLength), sizeof(deckLength));

				// Salva as cartas válidas no vetor uma por uma
				for (unsigned i = 0; i < deckLength; i++) {
					fout.write((char*)&(deck[i]), sizeof(Card));
				}

				fout.close();

				// Fallthrough para o próximo case para encerrar o programa
			}
			case 'E': {
				return EXIT_SUCCESS;
			}
			default : {
				cout << "\x1B[91m" << "Invalid option. Try again." << "\033[0m" << endl;
				// Continua para a próxima iteração do loop
				continue;
			}
		}
	}

	return EXIT_SUCCESS;
}
