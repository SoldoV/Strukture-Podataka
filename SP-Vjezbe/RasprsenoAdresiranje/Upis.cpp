#include "Header.h"

void format(FILE *f)
{
	zapis pretinac[C];

	for (int i = 0; i<C; i++)
		pretinac[i].sifra = 0;

	for (int i = 0; i<M; i++) {
		fseek(f, i*BLOK, SEEK_SET);
		fwrite(pretinac, sizeof(pretinac), 1, f);
	}
}

int adresa(int sifra)
{
	return sifra%M;
}

int upis(FILE *f, int adr, zapis pom)
{
	zapis pretinac[C];

	int poc = adr;
	int i;
	i = poc;

	do {
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++) {
			if (pretinac[j].sifra == pom.sifra) {
				return 0;
			}if (pretinac[j].sifra == 0) {
				pretinac[j] = pom;
				fseek(f, i * BLOK, SEEK_SET);
				fwrite(pretinac, sizeof(pretinac), 1, f);
				return 1;
			}
		}
		i = (i + 1) % M;
	} while (i != poc);
	return 0;
}

void prepisi(FILE *fizlaz, FILE *fulaz)
{
	zapis pom;
	int adr;
	int i = 0;
	while (fscanf(fulaz, "%d,%[^,],%f", &pom.sifra, &pom.naziv, &pom.cijena) != EOF)
	{
		adr = adresa(pom.sifra);
		printf("\n%d: Pret:%d -> %d %s %.2f",i++, adr, pom.sifra, pom.naziv, pom.cijena);
		upis(fizlaz, adr, pom);
	}
	printf("\nUkupno: %d", i);
}

void parametri()
{
	printf("\n\nParametri:");
	printf("\n-> BLOK = %d", BLOK);
	printf("\n-> Zapis = %d", sizeof(zapis));
	printf("\n-> Pretinac = %d", C * sizeof(zapis));
	printf("\n-> Smece = %d", BLOK - C * sizeof(zapis));
	printf("\n-> C = %d", C);
	printf("\n-> M = %d", M);
}

void ispis(FILE *f)
{
	printf("\n\nDatoteka:\n");
	zapis pretinac[C];
	int br = 0;
	for (int i = 0; i < M; i++)
	{
		fseek(f, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		printf("%d ->\t", i);
		for (int j = 0; j < C; j++)
		{
			if (pretinac[j].sifra != 0) {
				printf("%03d\t", pretinac[j].sifra);
				br++;
			}
			else
				printf("...\t");
		}
		printf("\n");
	}
	printf("Ukupno: %d", br);

	parametri();
}

FILE * ucitaj(char *name)
{
	FILE *f, *fb;

	if (name == NULL)
		return NULL;

	f = fopen(name, "r");
	if (f == NULL)
		return NULL;

	fb = fopen("artikli.dat", "wb+");
	if (fb == 0)
		return NULL;

	
	format(fb);
	prepisi(fb, f);

	return fb;
}