#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct c {
	int broj;
	struct c *sljed;
}
cvor;


typedef struct s {
	cvor *vrh;
} Stog;

void init(Stog *stog) {
	stog->vrh = NULL;
}

cvor *noviCvor(int broj) {
	cvor *novi;
	if ((novi =(cvor *) malloc(sizeof(cvor))) == NULL)
		return NULL;
	novi->broj = broj;
	novi->sljed = NULL;
	return novi;
}

int dodaj(Stog *stog, int broj) {

	return 1;
}

int skini(Stog *stog, int *broj) {

	return 1;
}

void main() {
	Stog stog;
	init(&stog);

	dodaj(&stog, 5);
	dodaj(&stog, 10);
	dodaj(&stog, 115);

	int broj;
	skini(&stog, &broj);
	skini(&stog, &broj);
	skini(&stog, &broj);
	skini(&stog, &broj);
}