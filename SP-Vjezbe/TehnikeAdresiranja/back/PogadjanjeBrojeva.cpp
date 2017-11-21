#include "Zaglavlje.h"
#define MAX 10

void pogadjanjeBrojeva() {

	srand(time(NULL));
	int broj = rand() % 100;

	int brPokusaja = 0;
	int novi=0;

	do {
		printf("\nUnesi broj: ");
		scanf("%d", &novi);

		if (broj > novi)
			printf("Veci!\n");
		else if (broj < novi)
			printf("Manji!");
		else {
			printf("Pogodili ste !!!");
			return;
		}
		brPokusaja++;
	} while (novi != broj && brPokusaja < MAX);

	printf("Žao mi je pokušajte ponovo!");
}