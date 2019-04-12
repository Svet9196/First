#include <stdio.h>
#include <limits.h>

unsigned rightror(unsigned x, int n);
int main(int argc, char** argv)
{
	unsigned x = 1121;
	x = rightror(x, 2);
	printf("%u\n", x);
	return 0;
}
unsigned rightror(unsigned x, int n) 
{
	unsigned x_right = x >> n;
	unsigned x_left = x << ((sizeof (unsigned) * CHAR_BIT) - n);
	x = x_right | x_left;
	return x;
}