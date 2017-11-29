#include "Header.h"

int brojZapisa(FILE *f)
{
	zapis pretinac[C];
	int br = 0;
	for (int i = 0; i < M; i++) {
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++) {
			if (pretinac[j].sifra != 0)
				br++;
		}
	}
	return br;
}

int pronadji(FILE *f) {

}

void main()
{
	FILE *f; 
	if ((f = ucitaj("artikli.txt")) == NULL)
		return;

	ispis(f);
	parametri();
	int broj;

	broj = brojZapisa(f);

	printf("\n\n");
}