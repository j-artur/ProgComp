#include <iostream>
#include <string>

using namespace std;

struct Book
{
	char title[40];
	char author[20];
};

struct Game
{
	char title[20];
	char platform[20];
};

void showBook(Book);
void showGame(Game);

int main()
{
	Book rentedBooks[10] =
	{
		{ "Harry Potter and the Sorcerer's Stone", "JK. Rowling" },
		{ "Percy Jackson and the Lightninh Thief", "Rick Riordan"},
		{ "Dom Quixote de la Mancha", "Miguel de Cervantes" }
	};

	Game rentedGames[10] =
	{
		{ "God of War", "Playstation 2" },
		{ "Super Mario World", "Super Nintendo"},
		{ "Hollow Knight", "PC, Switch" }
	};

	unsigned int input;
	cout << "Press 1 to rent a book.\n";
	cout << "Press 0 to rent a game.\n";
	cin >> input;
	cin.ignore();

	if (input == 1)
	{
		Book book;
		cout << "Rent a new book.\n";

		cout << "Book's title: ";
		cin.getline(book.title, 40);
		cout << "Book's author: ";
		cin.getline(book.author, 20);

		rentedBooks[3] = book;

		cout << '\n';

		cout << "Your rented books:\n";

		cout << left; cout.width(3); cout << "N.";
		cout << left; cout.width(20); cout << "Title";
		cout << left; cout.width(20); cout << "Author";
		cout << '\n';

		for (size_t i = 0; i < 4; i++)
		{
			cout << left; cout.width(3); cout << i + 1;
			showBook(rentedBooks[i]);
		}
	}
	else if (input == 0)
	{
		Game game;
		cout << "Rent a new game.\n";

		cout << "Game's title: ";
		cin.getline(game.title, 20);
		cout << "Game's author: ";
		cin.getline(game.platform, 20);

		rentedGames[3] = game;

		cout << '\n';

		cout << "Your rented games:\n";
		cout << left; cout.width(3); cout << "N.";
		cout << left; cout.width(20); cout << "Title";
		cout << left; cout.width(20); cout << "Platforms";
		cout << '\n';

		for (size_t i = 0; i < 4; i++)
		{
			cout << left; cout.width(3); cout << i + 1;
			showGame(rentedGames[i]);
		}
	}

	return 0;
}

void showBook(Book book)
{
	cout << left; cout.width(40); cout << book.title;
	cout << left; cout.width(20); cout << book.author;
	cout << '\n';
}

void showGame(Game game)
{
	cout << left; cout.width(20); cout << game.title;
	cout << left; cout.width(20); cout << game.platform;
	cout << '\n';
}
