#include "Zaglavlje.h"

void pogadjanjeBrojeva2(int broj)
{
	int poc = 0;
	int kraj = 100;
	int br;
	do {
		br = (poc + kraj) / 2;
		printf("\n Pogadjam %d", br);
		if (br > broj)
			kraj = br;
		else if (br < broj)
			poc = br;
		else {
			printf("Bravooo!");
			return;
		}

	} while (1);
}