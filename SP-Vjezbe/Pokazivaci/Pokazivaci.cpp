#include <stdio.h>

int main()
{
	int a = 1;
	int var = 5;
	printf("Value: %d\n", var);
	printf("Address: %u", &var);  //Notice, the ampersand(&) before var.
	return 0;
}