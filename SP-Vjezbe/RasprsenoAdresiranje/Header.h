#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struktura
typedef struct {
	int sifra;
	char naziv[60];
	float cijena;
}zapis;

//Parametri
#define MAXZAPIS 50
#define BLOK 512
#define C (int)(BLOK/sizeof(zapis))
#define M (int) ((MAXZAPIS/C) * 1.3)

FILE * ucitaj(char *name);
void parametri();
void ispis(FILE *f);
