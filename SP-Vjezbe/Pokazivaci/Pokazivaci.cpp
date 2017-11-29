/* Primjer korištenja pokazivaèa u C-u*/
#include <stdio.h>
int main() {

	int* pc;		//Pokazivaè
	int c;			//Varijabla

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