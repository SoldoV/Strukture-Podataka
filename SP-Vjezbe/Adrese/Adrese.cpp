/* Primjer korištenja adresnog operatora u C-u. */
#include <stdio.h>

int main()
{
	int var = 5;
	printf("Vrijednost: %d\n", var);
	printf("Adresa: %x\n", &var);  //Obratite pažnju na adresni operator & prije var
	return 0;
}