#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */
void print_char(int *v, int n)
{
    unsigned char *p =(unsigned char *)v;
    for(unsigned char i = 0; i < sizeof(int)/sizeof(char)*n; i++)
        printf("%p -> 0x%hhx\n", p+i, *(p+i));
}

void print_short(int *v, int n)
{
    short *p = (short *)v;
    for(unsigned short i = 0; i < sizeof(int)/sizeof(short) * n; i++)
          printf("%p -> 0x%hhx\n", p+i, *(p+i));
}

void print_int(int *v, int n)
{
    int *p = v;
    for( int i = 0; i < n; i++)
        printf("%p -> 0x%hhx\n", p+i, *(p+i));
}
int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    printf("Print char:\n");
    print_char(v,5);

    printf("Print short:\n");
    print_short(v,5);

    printf("Print int:\n");
    print_int(v,5);
    return 0;
}
