#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}
void month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char* p;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	p = &daytab[leap][1];
	for (i = 1; i < month; i++) {
		day += *p;
		++p;
	}
	return day;
}
void month_day_pointer(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;
	char* p;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	p = &daytab[leap][1];
	for (i = 1; yearday > * p; i++) {
		yearday -= *p;
		++p;
	}
	*pmonth = i;
	*pday = yearday;
}
int main(void)
{
	int year, month, day, yearday;
	year = 2000;
	month = 3;
	day = 1;
	printf("The date is: %d-%02d-%02d\n", year, month, day);
	printf("day_of_year: %d\n", day_of_year(year, month, day));
	printf("day_of_year_pointer: %d\n",
		day_of_year_pointer(year, month, day));

	yearday = 61;
	month_day(year, yearday, &month, &day);
	printf("Yearday is %d\n", yearday);
	printf("month_day: %d %d\n", month, day);
	month_day_pointer(year, yearday, &month, &day);
	printf("month_day_pointer: %d %d\n", month, day);
	return 0;
}