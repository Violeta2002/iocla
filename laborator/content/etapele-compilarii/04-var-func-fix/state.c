#include<string.h>
//const char *init_shopping[3];
char shopping_list[3][8];

void init_shopping(void)
{
	strcpy(shopping_list[0], "cheese");
	strcpy(shopping_list[1], "wine");
	strcpy(shopping_list[2], "dessert");
}
