#include "Header.h"

void format(FILE *f)
{
	zapis pretinac[C];

	for (int i = 0; i < C; i++)
		strcpy(pretinac[i].ID, "0");

	for (int i = 0; i<M; i++) {
		fseek(f, i*BLOK, SEEK_SET);
		fwrite(pretinac, sizeof(pretinac), 1, f);
	}
}

int adresa(char *sifra)
{
	int sumasci = 0;
	for (int i = 0; i < strlen(sifra); i++)
		sumasci += sifra[i];

	int ssif = (int) pow(sumasci, 2.0f);
	return ssif%M;
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
			if (strcmp(pretinac[j].ID,pom.ID) == 0) {
				return 0;
			}if (strcmp(pretinac[j].ID,"0") == 0) {
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
	time_t START = time(NULL);
	while (fscanf(fulaz, "%[^;];%[^;];%[^;];%[^\n]\n", &pom.ID, &pom.SongID, &pom.ArtistName, &pom.SongTitle) != EOF)
	{
		adr = adresa(pom.ID);
		//printf("\n%s %s %s %s", pom.ID, pom.SongID, pom.ArtistName, pom.SongTitle);
		upis(fizlaz, adr, pom);
		i++;
	}
	time_t STOP = time(NULL);

	int time = (int)difftime(STOP, START);
	printf("\nUkupno: %d sec", time);
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

//void ispis(FILE *f)
//{
//	printf("\n\nDatoteka:\n");
//	zapis pretinac[C];
//	int br = 0;
//	for (int i = 0; i < M; i++)
//	{
//		fseek(f, i*BLOK, SEEK_SET);
//		fread(pretinac, sizeof(pretinac), 1, f);
//		printf("%d ->\t", i);
//		for (int j = 0; j < C; j++)
//		{
//			if (pretinac[j].sifra != 0) {
//				printf("%03d\t", pretinac[j].sifra);
//				br++;
//			}
//			else
//				printf("...\t");
//		}
//		printf("\n");
//	}
//	printf("Ukupno: %d", br);
//
//	parametri();
//}

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
	parametri();
	prepisi(fb, f);

	return fb;
}