/* FORK
 * * (c) 2015-2016 M. Anwar Ma’sum and Rahmat M. Samik-Ibrahim
 * * This is a free software ------ Rev. 06 - 01-Apr-2016
 * */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
void main() {
	pid_t pid1, pid2, pid3;
	pid1 = pid2 = pid3 = getpid();
	printf(" 2016 2015 2014--\n==================\n");
	printf("[%4d][%4d][%4d]\n", pid1, pid2, pid3);
	fork();
	pid1 = getpid();
	wait(NULL);
	pid2 = getpid();
	if(!fork()) {
		pid2 = getpid();
		fork();
	}
	pid3 = getpid();
	wait(NULL);
	printf("[%4d][%4d][%4d]\n", pid1, pid2, pid3);
}
