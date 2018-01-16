#include <stdio.h>
#define MAX 10

typedef struct s {
	int niz[MAX];
	int ulaz;
	int izlaz;
} Red;

void init(Red *red) {
	red->ulaz =  -1;
	red->izlaz = -1;
}

int dodaj(Red *red, int broj) {
	if (red->ulaz + 1 == red->izlaz)
		return 0;
	red->ulaz = (red->ulaz + 1) % MAX;
	red->niz[red->ulaz] = broj;
	return 1;
}

int skini(Red *red,  int *broj) {
	if (red->izlaz == red->ulaz)
		return 0;
	red->izlaz = (red->izlaz + 1) % MAX;
	*broj = red->niz[red->izlaz];
	return 1;
}

void main() {

	Red red;
	init(&red);

	dodaj(&red, 5);
	dodaj(&red, 10);
	int broj;
	skini(&red, &broj);
	skini(&red, &broj);
	skini(&red, &broj);
}