/* Primjer korištenja adresnog operatora u C-u. */
#include <stdio.h>

#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

int main()
{
	unsigned int var = 5;
	printf("Vrijednost varijable : %d\n", var);
	printf("Adresa: %x\n", &var);  //Obratite pažnju na adresni operator & prije var
	return 0;
}