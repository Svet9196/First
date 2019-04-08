#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int revstringf(char line[], char revline[]);

int main()
{
	char line[MAXLINE];
	char revline[MAXLINE];

	while ((getline(line, MAXLINE)) > 0) {
		revstringf(line, revline);
		printf("%s", revline);
	}
	return 0;
}
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
int revstringf(char s[], char revline[]) {
	int i, ii;
	i = 0;
	while (s[i] != '\n')
		++i;
	ii = 0;
	for (i = i - 1; i >= 0; --i) {
		revline[ii] = s[i];
		++ii;
	}
	revline[ii] = '\n';
	revline[++ii] = '\0';
	return 0;
}