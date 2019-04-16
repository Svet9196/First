#include <stdio.h>

void strn_cpy(char *s, char *t, size_t n);
int strn_cmp(char* s, char* t, size_t n);
char* strn_cat(char s[], char t[], size_t n);

int main(int argc, char** argv) {
	char s[100] = "First string";
		char *ps;
	int r;

	printf("Test string s:\n%s\n", s);
	printf("\n");

	strn_cpy(s, "This is the", 12);
	printf("strn_cpy(s, \"This is the \", 30):\ns: %s\n", s);
	printf("Should be padded with 0s. Test s[12] == 0? %d\n", s[12] == '\0' ? 1 : 0);
	printf("Should be padded with 0s. Test s[16] == 0? %d\n", s[16] == '\0' ? 1 : 0);
	printf("Should be padded with 0s. Test s[29] == 0? %d\n", s[29] == '\0' ? 1 : 0);

	ps = strn_cat(s, "concatenated string.", 20);
	printf("strn_cat(s, \"concatenated string. But this sentence must not be copied.\", 20):\ns: %s\n", ps);
	printf("\n");

	r = strn_cmp(s, "This is the", 5);
	printf("strn_cmp(s, \"This is the\", 5) returns %d\n", r);
	r = strn_cmp(s, "This is the", 11);
	printf("strn_cmp(s, \"This is the\", 11) returns %d\n", r);
	r = strn_cmp(s, "This is the", 15);
	printf("strn_cmp(s, \"This is the\", 15) returns %d\n", r);
	r = strn_cmp(s, "UVWXYZ", 6);
	printf("strn_cmp(s, \"UVWXYZ\", 6) returns %d\n", r);

	return 0;
}

void strn_cpy(char *s, char *ct, size_t n) {
	int i = 0;
	while ((*s++ = *ct++) && (i++ < n));
	while (i++ < n)
		* s++ = '\0';
	*--s = '\0';
}

int strn_cmp(char *cs, char *ct, size_t n) {
	int i = 0;
	for (; (*cs == *ct) && (i++ < n); cs++, ct++)
		if (*cs == '\0' || i == n)
			return 0;
	return *cs - *ct;
}

char* strn_cat(char *s, char *ct, size_t n) {
	int i = 0;
	char* p = s;
	while (*s)
		s++;
	while ((*s++ = *ct++) && (i++ < n));
	*s = '\0';
	return p;
}