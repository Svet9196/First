/*for  (i=O; i<lim-1&&(c=getchar(»   1= '\n'&&c  1=EOF;++i)s[i]=c*/
#include <stdio.h>
#define lim 80
main()
{

	int c;
	int i = 0;
	char s[lim];
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			break;
		if (i <= lim - 1)
			break;
		s[i] = c;
		i++;

	}
}


