#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80


int getline(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];
	while ((len = getline(line, MAXLINE)) > 0)
	{
		if (line[len - 1] != '\n')
		{
			printf("biiger than 1000:\n\n");
			printf("%s\n\n", line);
		}
		else if (len > MINLINE)
			printf("%s\n\n", line);
	} 
	return 0;
}
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == 'n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;

}


