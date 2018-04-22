/*
 * * (c) 2017 Rahmat M. Samik-Ibrahim
 * * http://rahmatm.samik-ibrahim.vlsm.org/
 * * This is free software.
 * * REV02 Mon Dec 11 17:46:01 WIB 2017
 * * START Sun Dec 3 18:00:08 WIB 2017
 * */
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define LOOP 3
#define OFFSET 1000
void main(void) {
	    int basePID = getpid() - OFFSET;

		    for (int ii=0; ii < LOOP; ii++) {
				        if(!fork()) {
							printf("PID[%d]-PPID[%d]\n",
									getpid() - basePID,
									getppid() - basePID);
							fflush(NULL);
						}
						wait(NULL);

			}
}
