/*
 * * (c) 2005-2017 Rahmat M. Samik-Ibrahim
 * * This is free software. Feel free to copy and/or
 * * modify and/or distribute it, provided this
 * * notice, and the copyright notice, are preserved.
 * * REV02 Wed May 17 16:52:02 WIB 2017
 * * REV00 Wed May 3 17:07:09 WIB 2017
 * *
 * * fflush(NULL): flushes all open output streams
 * * fork():
 * creates a new process by cloning
 * * getpid():
 * get PID (Process ID)
 * * wait(NULL):
 * wait until the child is terminated
 * *
 * */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void main(void) {
	int firstPID = (int) getpid();
	int
		RelPID;
	fork();
	wait(NULL);
	fork();
	wait(NULL);
	fork();
	wait(NULL);
	RelPID=(int)getpid()-firstPID+1000;
	printf("RelPID: %d\n", RelPID);
	fflush(NULL);
}
