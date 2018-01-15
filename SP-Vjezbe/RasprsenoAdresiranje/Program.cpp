#include "Header.h"

int prebroji(FILE *f) {
	zapis pretinac[C];
	int br = 0;
	for (int i = 0; i < M; i++)
	{
		fseek(f, i*BLOK, SEEK_SET);
		fread(&pretinac[0], sizeof(zapis) *C, 1, f);
		for (int j= 0; j < C; j++)
		{
			if (pretinac[j].sifra != 0)
				br++;
		}
	}
	return br;
}

float gustoca(FILE *f)
{
	return ((float)prebroji(f) / (C*M))*100;
}

void format1(FILE *f) {
	zapis pretinac[C];
	
	for (int i = 0; i < C; i++)
		pretinac[i].sifra = 0;

	for (int i = 0; i < M; i++){
		fseek(f, i*BLOK, SEEK_SET);
		fwrite(pretinac, sizeof(zapis)*C, 1, f);
	}
}

int pronadji(FILE *f, int sifra) {
	zapis pretinac[C];
	int poc = adresa(sifra);
	int i = poc;
	do {
		fseek(f, i*BLOK, SEEK_SET);
		fread(&pretinac[0], sizeof(zapis) *C, 1, f);
		for (int j = 0; j < C; j++)
		{
			if (pretinac[j].sifra == sifra)
				return 1;
		}
		i = (i + 1) % M;
	} while (i != poc);
	return 0;
}

int brojPreljeva(FILE *f, int rbp) {
	zapis polje[C];
	fseek(f, rbp*BLOK, SEEK_SET);
	fread(polje, sizeof(polje), 1, f);
	int br = 0;
	for (int i = 0; i < C; i++){
		if (adresa(polje[i].sifra)!=rbp)
			br++;
	}
	return br;
}

int praznih(FILE *f) {

	zapis pretinac[C];
	float sum = 0;
	int br = 0;

	for (int i = 0; i < M; i++)
	{
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++)
		{
			if (pretinac[j].sifra == 0) {
				br++;
			}
		}
	}

	return br;
}

int izbrisi(char *nazivDatoteke, int indeks)
{
	FILE *f = fopen(nazivDatoteke, "rb+");
	if (f == NULL)
		return -1;
	int br = 0;
	zapis pom;
	fseek(f, indeks * BLOK, SEEK_SET);

	zapis polje[C];
	fread(&polje[0], sizeof(zapis)*C, 1, f);
	for (int i = 0; i < C; i++)
	{
		if(polje[i].sifra != 0){
			polje[i].sifra = 0;
			br++;
		}
	}
	fseek(f, indeks * BLOK, SEEK_SET);
	fwrite(polje, sizeof(polje), 1, f);

	/*for (int i = 0; i < C; i++)
	{
		fread(&pom, sizeof(zapis), 1, f);
		if (pom.sifra != 0)
		{
			pom.sifra = 0;
			br++;
			fseek(f, -sizeof(zapis), SEEK_CUR);
			fwrite(&pom, sizeof(zapis), 1, f);
		}
	}*/
	return br;
}

zapis *pronadji(char *nazivDatoteke, int sifra) {
	FILE *f = fopen(nazivDatoteke, "rb+");
	if (f == NULL)
		return -1;

	int poc = adresa(sifra);
	zapis polje[C];
	int i = poc;
	do {
		fseek(f, i*BLOK, SEEK_SET);
		fread(&polje[0], sizeof(zapis) *C, 1, f);
		for (int i = 0; i < C; i++)
		{
			if (polje[i].sifra == sifra) {
				return polje;
			}
		}

		i = (i + 1) % M;
	} while (i != poc);

	return NULL;
}

void main()
{
	FILE *f; 
	/*if ((f = ucitaj("artikli.txt")) == NULL)
		return;*/
	f = fopen("artikli.dat", "r");
	ispis(f);

	//format1(f);
	int br = prebroji(f);
	float g = gustoca(f);

	int rez = praznih(f);

	printf("\n\n");
}