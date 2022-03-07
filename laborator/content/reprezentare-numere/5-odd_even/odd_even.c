#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	for(int c = nr_bits; c >= 0; c--) {
		int k = number >> c;
	if( k & 1)
		printf("1");
	else
		printf("0");
	}
	printf("\n");
}

void check_parity(int *numbers, int n)
{
	for(int i = 0; i < n; i++)
		if((*(numbers + i) ^ 1 )== *(numbers +i) +1)
			print_binary(*(numbers + i), 8 * sizeof(int));
		else 
			printf("0x%x\n", *(numbers + i));
}

int main()
{
	int n, *numbers;
	scanf("%d", &n);
	numbers = malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
		scanf("%d", numbers+i);
	check_parity(numbers, n);
	return 0;
}

