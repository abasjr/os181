#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) 
	{
	printf("Start:PID[%d] PPID[%d]\n", getpid(), getppid());
	fflush(NULL);
	if (fork() == 0) 
	{
		/* START BLOCK
		 * END
		 * BLOCK */
		execlp("./00-fork", "00-fork", NULL);
		printf("Child:");
	} 
	else 
	{
		wait(NULL);
		printf("Parent:");
	}
	printf("PID[%d] PPID[%d] <<< <<< <<<\n", getpid(), getppid());
}
