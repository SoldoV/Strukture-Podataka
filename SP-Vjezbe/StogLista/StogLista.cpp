#include <stdio.h>
#include <stdlib.h>

typedef struct c {
	int broj;
	struct c *sljed;
}cvor;

typedef struct s {
	cvor *vrh;
}Stog;

void init(Stog *stog) {
	stog->vrh = NULL;
}

cvor *noviCvor(int broj) {
	cvor *novi;
	if ((novi = (cvor *)malloc(sizeof(cvor))) == NULL)
		return NULL;
	novi->broj = broj;
	novi->sljed = NULL;
	return novi;
}
int dodaj(Stog *stog, int broj) {
	cvor *pom = noviCvor(broj);
	if (pom == NULL)
		return -1;
	pom->sljed = stog->vrh;
	stog->vrh = pom;
	return 1;
}

int skini(Stog *stog, int *element) {
	if (stog->vrh == NULL)
		return -1;
	cvor *pom = stog->vrh;
	stog->vrh = pom->sljed;
	*element = pom->broj;
	free(pom);
	return 1;
}

int velicina(Stog *stog) {
	int element;
	int br = 0;
	Stog pom;
	init(&pom);
	while (skini(stog, &element)>0) {
		dodaj(&pom, element);
		br++;
	}
	while (skini(&pom, &element)>0)
		dodaj(stog, element);
	return br;
}

int prazni(Stog *stog) {
	int element;
	int br = 0;
	while (skini(stog, &element) > 0)
		br++;
	return br;
}

void main() {
	Stog stog;
	init(&stog);

	dodaj(&stog, 10);
	dodaj(&stog, 10);
	dodaj(&stog, 11);

	prazni(&stog);
	int broj = velicina(&stog);
}