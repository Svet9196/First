#include <stdio.h>

static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday);
int main(void)
{
	int day, mo, dat;
	day = day_of_year(1996, 11, 21);
	printf("%d\n", day);
	month_day(1996, 326);
		return 0;
}

int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	printf("Month: %d, Day: %d\n", i, yearday);
}