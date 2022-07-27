struct Date {
	short day;
	short month;
	short year;
};

struct Time {
	short hour;
	short min;
};

struct Event {
	Date date;
	Time time;
	char description[18];
};
