#include <stdio.h>

main()
{

	int c, nl, ns, nt;
	nl = 0;
	ns = 0;
	nt = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			++nl;
		}
		if (c == '\t') {
			++nt;
		}
		if (c == ' ') {
			++ns;
		}



	}
	printf("Blanks%d\nTabs%d\nNewlines%d\n", ns, nt, nl);
}



