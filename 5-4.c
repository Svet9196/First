#include <stdio.h>
#include <string.h>

#define STR_BUFFER 10000

int  strend(char*, char*);
void strrev(char*, char*);

int main(int argc, char* argv[])
{
	char string1[STR_BUFFER] = "ole.";
	char string2[STR_BUFFER] = "hole. ";

	printf("String 1: %s\n", string1);
	printf("String 2: %s\n", string2);

	if (strend(string1, string2)) {
		printf("String 2 occurs at the end of string 1!\n");
	}
	else {
		printf("String 2 does not occur at the end of string 1.\n");
	}
	return 0;
}

int strend(char* s, char* t)
{
	char* s_pt, * t_pt;
	char s_rev[STR_BUFFER];
	char t_rev[STR_BUFFER];

	s_pt = s_rev;
	t_pt = t_rev;

	strrev(s, s_rev);
	strrev(t, t_rev);

	for (; *s_pt == *t_pt; s_pt++, t_pt++) {
		if (*s_pt == ' ' || *s_pt == '\t' || *s_pt == '\0') {
			return 1; 
		}
		else {
			return 0;
		}
	}

	return 0;
}


void strrev(char* str, char* dest)
{
	int i = strlen(str) - 1; 
	for (str += i; i >= 0; dest++, str--, i--) {
		
		*dest = *str;
	}
	dest++;
	dest = '\0';
}