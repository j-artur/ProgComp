#include <iostream>
#include <fstream>
#include "generator.h"

using namespace std;

// Usa as variáveis globais do arquivo principal
extern Card deck[32];
extern unsigned short deckLength;

// Imprime no console uma mensagem com uma linha embaixo
void printHeader(const char* message) {
	cout << message << endl;
	for (unsigned i = 0; message[i] != '\0'; i++) {
		cout << '-';
	}
	cout << endl;
}

// Pede ao usuário para preencher as informações de uma carta e a retorna
Card inputCard() {
	Card card;

	cout.width(15); cout << left << "Name" << " : ";
	cin >> card.name;

	cout.width(15); cout << left << "HP" << " : ";
	cin >> card.hp;

	cout.width(15); cout << left << "Attack" << " : ";
	cin >> card.attack;

	cout.width(15); cout << left << "Defense" << " : ";
	cin >> card.defense;

	cout.width(15); cout << left << "Special Attack" << " : ";
	cin >> card.specialAttack;

	cout.width(15); cout << left << "Special Defense" << " : ";
	cin >> card.specialDefense;

	cout.width(15); cout << left << "Speed" << " : ";
	cin >> card.speed;

	return card;
}

// Tenta adicionar uma carta ao baralho
void addCard(Card& card) {
	// Se o baralho já contém o máximo de cartas, exibe erro e retorna
	if (deckLength == 32) {
		cout << "\x1B[91m" << "Deck is full" << "\033[0m" << endl;
		return;
	}

	// Adiciona a carta na próxima posição
	deck[deckLength] = card;

	// Aumenta o tamanho do baralho
	deckLength++;
}

// Tenta importar cartas de um arquivo de texto
void importCards(const char* file) {
	ifstream fin;
	fin.open(file);

	// Se não é possível abrir o arquivo, exibe erro e retorna
	if (!fin.is_open()) {
		cout << "\x1B[91m" << "Invalid file" << "\033[0m" << endl;
		return;
	}

	// Lê os dados do arquivo até chegar no final
	while (fin.good()) {
		Card card;
		fin >> card.name;
		fin >> card.hp;
		fin >> card.attack;
		fin >> card.defense;
		fin >> card.specialAttack;
		fin >> card.specialDefense;
		fin >> card.speed;

		// Adiciona a carta importada ao baralho
		addCard(card);
	}

	fin.close();
}

// Edita os atributos de uma carta
void updateCard(unsigned number) {
	auto index = number - 1;

	// Se a carta indicada não existe no baralho, exibe erro e retorna
	if (index >= deckLength) {
		cout << "\x1B[91m" << "Invalid card number" << "\033[0m" << endl;
		return;
	}

	cout << "Updating card " << number << ": " << deck[index].name << endl;

	// Altera uma carta na posição escolhida pelo usuário
	deck[index] = inputCard();
}

// Exclui uma carta do baralho
void deleteCard(unsigned number) {
	auto index = number - 1;

	// Se a carta indicada não existe no baralho, exibe erro e retorna
	if (index >= deckLength) {
		cout << "\x1B[91m" << "Invalid card number" << "\033[0m" << endl;
		return;
	}

	cout << "Deleting card " << number << "..." << endl;

	// Reduz o tamanho do baralho
	deckLength--;
	// A partir da posição indicada, copia a próxima carta para a posição anterior
	// Exclui a carta indicada e puxa as próximas para trás
	for (unsigned i = index; i < deckLength; i++) {
		deck[i] = deck[i + 1];
	}
	// A última carta fica duplicada na memória mas não é considerada pois a variável do tamanho foi reduzida
}

// Lista as cartas por nome
void listCards() {
	for (unsigned i = 0; i < deckLength; i++) {
		cout << i + 1 << ") " << deck[i].name << endl;
	}
	cout << endl;
}

// Imprime uma tabela com todos os atributos de todas as cartas
void listDeck() {
	// Linha com tamanho necessário para a largura da tabela
	const auto line = "---------------------------------------------------------------------------------------------------";

	cout << line << endl;
	cout << "| ";
	cout.width(3); cout << left << "N#";
	cout << " | ";
	cout.width(11); cout << left << "Name";
	cout << " | ";
	cout.width(10); cout << left << "HP";
	cout << " | ";
	cout.width(10); cout << left << "Attack";
	cout << " | ";
	cout.width(10); cout << left << "Defense";
	cout << " | ";
	cout.width(10); cout << left << "Sp.Attack";
	cout << " | ";
	cout.width(10); cout << left << "Sp.Defense";
	cout << " | ";
	cout.width(10); cout << left << "Speed";
	cout << " |";
	cout << endl;
	cout << line << endl;

	for (unsigned i = 0; i < deckLength; i++) {
		// Usa uma referência apenas para facilitar a interpretação
		auto& card = deck[i];

		cout << "| ";
		cout << '#'; cout.width(2); cout << left << i + 1;
		cout << " | ";
		cout.width(11); cout << left << card.name;
		cout << " | ";
		cout.width(10); cout << left << card.hp;
		cout << " | ";
		cout.width(10); cout << left << card.attack;
		cout << " | ";
		cout.width(10); cout << left << card.defense;
		cout << " | ";
		cout.width(10); cout << left << card.specialAttack;
		cout << " | ";
		cout.width(10); cout << left << card.specialDefense;
		cout << " | ";
		cout.width(10); cout << left << card.speed;
		cout << " | ";
		cout << endl;
	}
	cout << line << endl;
}
