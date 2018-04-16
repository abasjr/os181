#include <stdio.h>
#include <unistd.h>
void main(void) {
	int ii;
	printf("Sleeping 3s with fflush(): ");
	fflush(NULL);
	for (ii=0; ii < 3; ii++) {
		sleep(1);
		printf("x ");
		fflush(NULL);
	}
	printf("\nSleeping with no fflush(): ");
	for (ii=0; ii < 3; ii++) {
		sleep(1);
		printf("x ");
	}
	printf("\n");
}
