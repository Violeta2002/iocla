#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern)
{
	int p;
	if(strstr(s , pattern))
		p = strstr(s,pattern) - s;
	char *s2 = strcpy(s + p, s + p + strlen(pattern));
	memcpy(s + p, s2, strlen(s2) );
	return s;
}

int main(){
	char s[] = "Ana are mere";
	char *pattern = "re";

	// Decomentati linia dupa ce ati implementat functia delete_first.
	 printf("%s\n", delete_first(s, pattern));

	return 0;
}
