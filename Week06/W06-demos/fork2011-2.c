#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "myutils.h"

int main(int argc, char * argv[]) {
	int ii;
	for (ii=0;ii<2;ii++) {
		fork();
		waitpid(-1,NULL,0);
		sleep(1);
		printf("I am %d\n",(int) getpid());
	}
}
