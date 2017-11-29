#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct element {
	char	JMBG[13+1];
	char	ImePrezime[40+1];
	float	Prihod;
	float	PlatitiPorez;
};
typedef struct element zapis; 

// služi samo da bi se dobili podaci za testiranje
int prepisi(char *filenameIn, char *filenameOut) {
  FILE *fin, *fout;
  zapis z;
  int Br;

  fin = fopen(filenameIn, "r");
  fout = fopen(filenameOut, "w");

  if (fin == NULL || fout == NULL) {
    printf("pogreška prilikom prepisivanja podataka");
    return 0;
  }

  fscanf(fin, "%d\n", &Br);
  fwrite(&Br, sizeof(Br), 1, fout);

  while (fscanf(fin, "%s %[^\n] %f %f", z.JMBG, z.ImePrezime, &(z.Prihod), &(z.PlatitiPorez)) > 0) {
      fwrite(&z, sizeof(z), 1, fout);
  }

  fclose(fin);
  fclose(fout);
  return 1;
}

zapis* Ucitaj (char *FileName, int *BrElem) {
	int		i; //lokalne varijable
	long	Br;
	FILE 	*fp;
	zapis	*Polje = NULL;
	zapis	Elem;
	//Ovdje napisati kod
	fp = fopen(FileName, "rb");
	if (fp == NULL)
		return NULL;

	fread(&Br, sizeof(int), 1, fp);
	Polje = (zapis *)malloc(sizeof(zapis) * Br);

	for (int i = 0; i < Br; i++) {
		fread(&Elem, sizeof(zapis), 1, fp);
		Polje[i] = Elem;
	}

	return Polje;
}

int	MaxPorez( zapis *Polje, int BrElem ) {
	int	i, MaxInd = 0;
	float Max;
	//Ovdje napisati kod

	return MaxInd;
}

int main(){
	int	BrElem, MaxInd; //lokalne varijable
	char FileName[40];
	zapis *Polje;
	printf("Unesite ime datoteke : ");
	gets(FileName);
    prepisi("podaci.txt", FileName);

	Polje = Ucitaj(FileName, &BrElem);
	if( Polje != NULL ) {
		MaxInd = MaxPorez(Polje, BrElem);
		printf("Najviše poreza treba platiti %s, u iznosu od %f\n", Polje[MaxInd].ImePrezime, 
		Polje[MaxInd].PlatitiPorez );
	}
	free (Polje);
  return 0;
}
