#include <stdio.h>
#define MAXLEN 1000

int getline(char[], int);

main()
{

	char line[MAXLEN];
	int i, len, end;

	while ((len = getline(line, MAXLEN)) > 0) {
		end = len;
		for (i = len - 2; i >= 0; i--)
			if (line[i] == ' ' || line[i] == '\t')
				end = i;
			else
				break;
		if (end < len) {

			line[end] = '\n';
			line[end + 1] = '\0';
			len = end + 1;

		}
		if (len == 1)
			continue;
		printf("%2d: %s", end, line);
	}
	return 0;
}
int getline(char line[], int maxlen)
{

	int c, len;
	len = 0;
	while ((c = getchar()) != EOF) {
		if (len == maxlen) break;
	}
	line[len] = '\0';
	return len;
}
