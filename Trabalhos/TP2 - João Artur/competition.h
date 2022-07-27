using namespace std;

struct Time
{
	short hour;
	short minute;
};

struct Question
{
	short difficulty;
	Time start;
	Time finish;
};

struct Average
{
	float difficulty;
	float time;
};

struct Competitor
{
	char name[20];
	Question* questions;
};

void printCompetitorSummary(Question*, short);

Average getQuestionStatistics(Question*, short, size_t, short);

void printLineOf(char, short);

ostream& operator<<(ostream&, Time&);
istream& operator>>(istream&, Time&);
int operator-(Time, Time);

char letter(size_t);

void fillQuestion(Question*);

void printQuestionSummary(Question*);

ostream& operator<<(ostream&, Average&);
