#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int my_strcmp(const char *s1, const char *s2)
{
	while(*s1) {
	if(*s1 != *s2)
		return 1;
	
	s1++;
	s2++;	
	}
	return 0;
}

void *my_memcpy(void *dest, const void *src, size_t n);

	/*while(n--) {
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		//if(*(char *)(dest++) == '\0')
			//(char *)dest = (char *)realloc(dest, (strlen(dest) + 1) * sizeof(char));
	}
	*/


char *my_strcpy(char *dest, const char *src)
{
	char *p = dest;

	while(*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return p;
}

int main() {
	char s1[] = "Abracadabra";
	char s2[] = "Abracababra";
	char src[] = "Learn IOCLA, you must!";
	char *dest = malloc(sizeof(src));

	(void) s1;
	(void) s2;

	/*
	Decomentati pe rand cate un assert pe masura ce implementati o functie.
	Daca functia voastra este implementata corect atunci asertia se va realiza
	cu succes. In caz contrar, programul va crapa.
	*/
	assert(my_strcmp(s1, s2) == strcmp(s1, s2));
		printf("Those 2 string functions are the same\n");
	assert(my_memcpy(dest, src, sizeof(src)) == memcpy(dest, src, sizeof(src)));
	assert(my_strcpy(dest, src) == strcpy(dest, src));
		printf("my_strcpy and strcpy do the same thing");
	free(dest);

	return 0;
}
