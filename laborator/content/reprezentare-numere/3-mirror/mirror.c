#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mirror(char *s)
{
	char *p = s;
	unsigned i = 0;
	while(i <= strlen(s)/2)
	{
		char aux = *(p+i);
		*(p+i) = *(p+strlen(s) - i - 1);
		*(p + strlen(s) - i - 1) = aux;
		i++;
	}
	s = p;
}

int main()
{
	char s[256];
	scanf("%s", s);
	mirror(s);
	printf("%s", s);
	return 0;
}

