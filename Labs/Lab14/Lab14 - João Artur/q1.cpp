#include <iostream>

enum class State { empty, full };
enum class Food { soup, broth };

struct Bowl
{
	State state;
	Food food;
};

void hungry(Bowl*);
void showBowl(Bowl*);

int main()
{
	using namespace std;

	Bowl bowl = { State::full, Food::soup };

	Bowl* bowlPtr = &bowl;

	cout << "Before dinner:\n";
	showBowl(bowlPtr);

	hungry(bowlPtr);

	cout << "After dinner:\n";
	showBowl(bowlPtr);

	return 0;
}

void hungry(Bowl * bowlPtr)
{
	bowlPtr->state = State::empty;
}

void showBowl(Bowl * bowlPtr)
{
	using namespace std;

	cout << "The bowl is ";
	if (bowlPtr->state == State::empty)
		cout << "empty";
	else
		cout << "full of " << (bowlPtr->food == Food::soup ? "soup" : "broth");
	cout << ".\n";
}