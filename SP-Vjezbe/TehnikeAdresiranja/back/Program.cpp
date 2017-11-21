#include "Zaglavlje.h"

void main(int argc, char *argv[]) {
	int ind = 3;
	FILE *f = NULL;
	if (argc < 2) {
		printf("Ime datoteke nije definirano!");
		return;
	}

	f = fopen(argv[ind], "rb");
	if (f == NULL)
	{
		printf("Datoteka %s se ne može otvoriti!", argv[ind]);
	}

	//brojZapisaVelicina(f, ',');
	//velicina(f);
	/*int br;
	int *polje = index(f, &br);*/

	pogadjanjeBrojeva2(1);


	printf("\n\n\n");
}