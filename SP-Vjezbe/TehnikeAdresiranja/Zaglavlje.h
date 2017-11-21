#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>       /* time */

typedef struct
{
	int pbr;
	char naziv[30];
	char opcina[30];

} Mjesto;

int velicinaIBrojPodataka(FILE *f, int *vel, int col);
int pogodi(int br);
