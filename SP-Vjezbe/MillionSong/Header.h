#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Struktura
typedef struct s{
	char ID[20+1];
	char SongID[20+1];
	char ArtistName[30 + 1];
	char SongTitle[60 + 1];
	struct s *sljed;
}zapis;

//Parametri
#define MAXZAPIS 100000
#define BLOK 4096
#define C (int)(BLOK/sizeof(zapis))
#define M (int) ((MAXZAPIS/C) * 1.3)

FILE * ucitaj(char *name);
