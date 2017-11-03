#include <stdio.h> 
#define MAXRED 8
#define MAXSTUP 10

int zbroj(int *polje, int red, int stup)
{
	int suma = 0;
	//2. Izraèunaj sumu
	for (int i = 0; i<red; i++)
		for (int j = 0; j < stup; j++)
		{
			suma += polje[i*MAXSTUP + j];
		}
	return suma;
}

void main()
{
	int zb;
	int red, stup;
	int polje[MAXRED][MAXSTUP];

	FILE *f;
	f = fopen("UlazZaDvodimenzionalnoPolje.txt", "r");
	if (f == NULL) {
		printf("Greška! Datoteka se ne moze otvoriti!");
		return;
	}
	fscanf(f, "%d %d", &red, &stup);
	int pom;

	for(int i=0; i<red; i++)
		for (int j = 0; j < stup; j++) {
			fscanf(f, "%d", &pom);
			polje[i][j] = pom;
		}

	//1. Uèitaj podatke
	zb = zbroj(&polje[0][0], red, stup);

	printf("Zbroj je: %d", zb);
}

