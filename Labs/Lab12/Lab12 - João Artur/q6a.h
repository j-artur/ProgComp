struct Time
{
	unsigned short hour = 0;
	unsigned short minute = 0;
	unsigned short second = 0;
};

Time newTime();
void showTime(Time, unsigned char);
Time subtractTime(Time, Time);