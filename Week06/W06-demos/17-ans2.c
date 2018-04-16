/*
 * * (c) 2016 Rahmat M. Samik-Ibrahim -- This is free software
 * * REV02 Tue Apr 11 19:09:21 WIB 2017
 * * START Sun Dec 04 00:00:00 WIB 2016
 * * wait()
 * = suspends until its child terminates.
 * * fflush()
 * = flushes the user-space buffers.
 * * getppid() = get parent PID
 * * ASSUME first pid > 2000; first ppid < 1000
 * */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define  NN 2

void main (void) {
	int id1000=getpid()-1000;
	for (int ii=1; ii<=NN; ii++) {
		fork();
		wait(NULL);
		int rPID = getpid()-id1000; // "relative"
		int rPPID=getppid()-id1000; // "relative"
		if (rPPID < 1) rPPID=999;
		printf("Loop [%d] - rPID[%d] - rPPID[%4.4d]\n", ii, rPID, rPPID);
	//	fflush(NULL);
	}
}
