#include <stdio.h>
#include <ctype.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS

void funkcija(int a){
	a++;
	if (a <= 10) {
		funkcija(a);
		printf("\n%d",a);
	}
}

int suma2(int a, int b)
{
	if (a > b)
		return 0;
	else
		return a + suma2(a + 1, b);
}

void obrnuto(char *niz, int d) {
	if (d < 0)
		return;
	printf("\n%c", niz[d]);
	obrnuto(niz, d - 1);
}

void obrnuto2(char *niz) {
	if (*niz  == '\0')
		return;
	obrnuto2(niz + 1);
	printf("\n%c", *niz);
}

void obrnuto3(int broj)
{
	if (broj <= 0)
		return;
	int zn = broj % 10;
	printf("\n%d", zn);
	obrnuto3((int)(broj / 10));
}

//int suma(int a, int b) {
//	int suma = 0;
//	for (int i = a; i <= b; i++) {
//		suma += i;
//	}
//	return 1;
//}

void main()
{
	int a = 0;

	//funkcija(a);
	/*a = suma2(2, 6);
	printf("Suma je : %d", a);*/
	//obrnuto(365);

	char niz[] = "Strukture";
	//obrnuto(&niz[0], strlen(niz) - 1);
	obrnuto2(niz);
	getchar();
}