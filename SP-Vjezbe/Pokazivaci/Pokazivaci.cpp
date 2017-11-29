/* Primjer korištenja pokazivaèa u C-u*/
#include <stdio.h>
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

int main() {

	unsigned int* pc;		//Pokazivaè
	unsigned int c;			//Varijabla

	c = 22;
	printf("Adresa varijable c:%u\n", &c);
	printf("Vrijednost varijable c:%d\n\n", c);

	pc = &c;
	printf("pc = &c;\n");
	printf("Adresa u pokazivacu pc:%u\n", pc);
	printf("Sadrzaj pokazivaca pc:%d\n\n", *pc);

	c = 11;
	printf("\nc = 11;\n");
	printf("Adresa u pokazivacu  pc:%u\n", pc);
	printf("Sadrzaj pokazivaca pc:%d\n\n", *pc);

	*pc = 2;
	printf("\n*pc = 2;\n");
	printf("Adresa varijable c:%u\n", &c);
	printf("Vrijednost varijable c:%d\n\n", c);

	return 0;
}