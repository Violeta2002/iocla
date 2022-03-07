#include <stdio.h>

void rotate_left(int *number, int bits)
{
	while(bits) {
		*number <<= 1;
		bits--;
	}
}

void rotate_right(int *number, int bits)
{
	while(bits) {
		*number >>= 1;
		bits--;
	}
}

int main()
{
	int number;
	int bits;
	scanf("%d", &number);
	scanf("%d", &bits);

	rotate_left(&number, bits);
	printf("%d\n", number);

	rotate_right(&number, bits);
	printf("%d\n", number);
	
	return 0; 
}

