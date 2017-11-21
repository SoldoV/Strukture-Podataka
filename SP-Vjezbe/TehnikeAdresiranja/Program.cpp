#include "Zaglavlje.h"

void main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Greška!!");
		return;
	}
	FILE *f;
	f = fopen(argv[1], "rb");

	if (f == NULL) {
		return;
	}
	/*int br;
	int vel;

	br = velicinaIBrojPodataka(f, &vel, 3);

	printf("\nBroj pod: %d", br);
	printf("\nVelicina: %d", vel);*/
	pogodi(4);

	printf("\n\n\n");
}