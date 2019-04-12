#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main(int argc, char** argv) {
	char s[MAXLINE];
	int n = -2147483648;

	itoa(n, s);
	printf("%s\n", s);
	
	return 0;
}

void reverse(char s[])
{
}
void itoa(int n, char s[]) {
	int i, sign;
	sign = n;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse (s);
}
void reverse(char s[]) {
	int i;
	int lenght = 0;
	for (i = 0; s[i] != '\0'; i++)
		lenght++;
	char temp [lenght];
	for (i = 0; i < lenght; i++)
		temp[i] = s[i];
	for (i = 0; i < lenght; i++)
		s[i] = temp[lenght - 1 - i];
}

