#include <stdio.h>
#include <string.h>

void squeeze(char s[], char t[]);

char string[] = "CBA";
char sstring[] = "ABC";

int
main(void)
{
	squeeze(string, sstring);
	return 0;
}

void
squeeze(char s[], char t[])
{
	int i, j, d;
	i = 0;
	j = 0;
	d = 0;
	if (strstr(s, t) == NULL)
		printf("%c", s[i]);
	s[j] = '\0';
}