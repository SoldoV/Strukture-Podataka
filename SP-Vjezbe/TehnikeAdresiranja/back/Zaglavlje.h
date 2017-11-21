#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>       /* time */

#define COLUMNS 3

typedef struct
{
	int pbr;
	char naziv[30];
	char opcina[30];

} Mjesto;

void ispis(int br, int vel);
void brojZapisaVelicina(FILE *f);
void velicina(FILE *f);
long *index(FILE *f, int *broj);
void pogadjanjeBrojeva();
void pogadjanjeBrojeva2(int broj);

