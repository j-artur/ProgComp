struct Card {
	char name[12];
	short hp;
	short attack;
	short defense;
	short specialAttack;
	short specialDefense;
	short speed;
};

void printHeader(const char*);

Card inputCard();

void addCard(Card&);
void importCards(const char*);
void updateCard(unsigned);
void deleteCard(unsigned);
void listCards();
void listDeck();
