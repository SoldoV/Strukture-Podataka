#include <stdio.h>
#define MAX 10

typedef struct s {
	int niz[MAX];
	int vrh;
} Stog;

void init(Stog *stog) {
	stog->vrh = -1;
}

int dodaj(Stog *stog, int broj) {
	if (stog->vrh >= (MAX - 1))
		return -1;
	stog->vrh++;
	stog->niz[stog->vrh] = broj;
	return 1;
}

int skini(Stog *stog, int *element) {
	if (stog->vrh == -1)
		return -1;
	*element = stog->niz[stog->vrh];
	stog->vrh--;
	return 1;
}

int zaviri(int *element, Stog *stog) {
	int broj;
	if(skini(stog, &broj) > 0)
		dodaj(stog, broj);
	*element = broj;

	return 1;
}

int velicina(Stog *stog) {
	int element;
	int br = 0;
	Stog pom;
	init(&pom);
	while (skini(stog,&element)>0){
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

int skiniMax(Stog *stog) {
	int element;
	int max;
	Stog pom;
	init(&pom);

	if (skini(stog, &max) > 0)
		dodaj(&pom, max);

	while (skini(stog, &element)>0) {
		dodaj(&pom, element);
		if (element > max)
			max = element;
	}

	while (skini(&pom, &element)>0)
		dodaj(stog, element);

	return max;
}

void fun(Stog *stog) {
	int element;
	Stog pom1;
	Stog pom2;
	init(&pom1);
	init(&pom2);
	
	while (skini(stog, &element)>0) 
		dodaj(&pom1, element);
	
	while (skini(&pom1, &element)>0)
		dodaj(&pom2, element);

	while (skini(&pom2, &element)>0)
		dodaj(stog, element);
}

void main() {
	Stog stog;
	init(&stog);
	dodaj(&stog, 10);
	dodaj(&stog, 10);
	dodaj(&stog, 11);

	int element;
	zaviri(&element, &stog);
	dodaj(&stog, 15);
	zaviri(&element, &stog);



}