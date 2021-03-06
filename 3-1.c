#include <stdio.h>

#define MAXSIZE 1000
int binsearch2(int x, int v[], int n);

int main(int argc, char** argv) {

	static int v[MAXSIZE]; 
	int x = MAXSIZE;
	int r, i;

	for (i = 0; i < MAXSIZE; i++)
		v[i] = i;

	r = binsearch2(x, v, MAXSIZE);
	printf("Position: %d\n", r);

	return 0;
}


int binsearch2(int x, int v[], int n) {

	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low < high) {
		mid = ((low + high) / 2) + 1;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid;
	}

	return x == v[low] ? low : -1;

}