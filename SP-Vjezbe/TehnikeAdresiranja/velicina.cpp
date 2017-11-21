#include "Zaglavlje.h"

int pogodi(int br) {
	int poc = 0;
	int kraj = 100;

	int p;
	do {
		p = (poc + kraj) / 2;
		printf("\npok. %d", p);
		if (p == br) {
			return 1;
		}
		else if (p < br) {
			poc = p;
		}
		else {
			kraj = p;
		}

	} while (1);

}

int velicinaIBrojPodataka(FILE *f, int *vel, int col)
{
	int zn;
	int br = 0;
	int brl = 0;

	fseek(f, 0, SEEK_END);
	br = (int)ftell(f);

	brl = br / sizeof(Mjesto);

	/*while ((zn = fgetc(f)) != EOF)
	{
		if (zn == 44)
			brl++;
		br++;
	}
	*/
	
	*vel = br;
	return brl / (col - 1);
}