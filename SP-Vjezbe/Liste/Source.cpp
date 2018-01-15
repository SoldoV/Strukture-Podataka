#include <stdio.h>
#include <stdlib.h>

struct s{
	int broj;
	struct s *sljed;
};
typedef struct s cvor;


void dodaj(cvor *glava, int broj)
{
	cvor*pom = glava;
	cvor *pp = glava;

	while (pom != 0)
	{
		pp = pom;
		pom = pom->sljed;
	}

	cvor *novi = (cvor *)malloc(sizeof(cvor));
	novi->broj = broj;
	novi->sljed = 0;

	pp->sljed = novi;

}

void ispis(cvor *glava) {
	printf("\nLista");
	while (glava!=NULL) {
		printf("\n%d", glava->broj);
		glava = glava->sljed;
	}
	printf("\n");
}


int dodjiza(cvor *glava, int broj, int _novi) {

	cvor *pom = glava;
	while (pom != 0)
	{
		if (pom->broj == broj) {
			cvor *novi = (cvor *)malloc(sizeof(cvor));
			novi->broj = _novi;

			novi->sljed = pom->sljed;
			pom->sljed = novi;
			return 1;
		}
		pom = pom->sljed;
	}
	return 0;
}

int izbrisiiza(cvor *glava, int broj) {

	cvor *pom = glava;
	while (pom != 0)
	{
		if (pom->broj == broj) {
			cvor *pp = pom->sljed;
			pom->sljed = pom->sljed->sljed;
			free(pp);
			return 1;
		}
		pom = pom->sljed;
	}
	return 0;
}

void main() {
	cvor *glava;

	cvor pom;
	pom.broj = 1;
	pom.sljed = 0;
	glava = &pom;
	
	dodaj(glava,2);
	dodaj(glava, 4);
	dodaj(glava, 51);
	ispis(glava);
	dodjiza(glava, 4, 3);
	ispis(glava);
}