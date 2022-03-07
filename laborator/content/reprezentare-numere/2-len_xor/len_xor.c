#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	int len = 0;
	const char *p = str;
	
	while(*p) {
		len++;
		p++;
	}
	return len;
}

void equality_check(const char *str)
{
	const char *p = str;
	int i = 0;
	int len = my_strlen(str);
	while(*(p+i))
	{
		if(!(*(p+i) ^ *(p+(i+(1<<i))%len)))
			printf("%p\n", p+i);
		i++;
	}
}

int main(void)
{
	char str[256];
	scanf("%s", str);
	int len = my_strlen(str);
	printf("%d\n", len);
	equality_check(str);
	return 0;
}

