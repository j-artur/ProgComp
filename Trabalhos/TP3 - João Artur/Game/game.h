struct Card {
	char name[12];
	short hp;
	short attack;
	short defense;
	short specialAttack;
	short specialDefense;
	short speed;
};

struct Player {
	char name[12];
	Card* cards[4];
	unsigned short points = 0;
};

short* selectAttributes(Card&, Card&);
void showScoreboard(Player*);