#include <stdio.h>

void rotate_left(int *number, int bits)
{
	int mask, size = sizeof(int) * 8;
	while(bits) {
		mask = (*number >> size) & 1;
		*number = (*number << 1) | mask;
		bits--;
	}
}

void rotate_right(int *number, int bits)
{
	int size = sizeof(int) * 8, mask;
	while(bits) {
		mask = *number & 1;
		*number = (*number >> 1) & (~(1 << size));
		*number = *number | mask << size;
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

	//rotate_right(&number, bits);
	//printf("%d\n", number);
	
	return 0; 
}

