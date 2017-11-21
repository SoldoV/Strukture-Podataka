#include "Zaglavlje.h"

void ispis(int br, int vel) {
	printf("\nBroj zapisa je %d", br);
	printf("\nVelicina zapisa je %d KB", vel);
}

void brojZapisaVelicina(FILE *f, char d) {
	int velicina = 0;
	int br = 0;
	int zn;
	while ( (zn = fgetc(f)) != EOF) {
		if (zn == d)
			br++;
		velicina++;
	}
	br = br / (COLUMNS - 1);
	ispis(br, velicina);
}

void velicina(FILE *f)
{
	int velicina=0;
	int br = 0;
	Mjesto mjesto;

	fseek(f, 0, SEEK_SET);
	/*while (fread(&mjesto, sizeof(Mjesto), 1,f) > 0) {
		br++;
	}*/

	fseek(f, 0, SEEK_END);
	velicina = (int)ftell(f);
	br = velicina / (sizeof(Mjesto));

	ispis(br , velicina);
}

long *index(FILE *f, int *broj)
{
	fseek(f, 0, SEEK_END);
	int br = ftell(f) / sizeof(Mjesto);
	*broj = br;
	long *index = (long *)malloc(sizeof(long)*br);

	fseek(f, 0, SEEK_SET);

	for (int i = 0; i < br; i++)
	{
		fseek(f, i * sizeof(Mjesto), SEEK_SET);
		index[i] = ftell(f);
	}

	return index;
}