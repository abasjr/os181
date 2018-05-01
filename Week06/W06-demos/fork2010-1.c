#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int my_fork(void);
int main(void)
{
	int ii, jj, kk;
	my_fork();
	ii = (int) getpid();
	my_fork();
	jj = (int) getpid();
	if (my_fork() > 0)
		my_fork();
	kk = (int) getpid();
	printf ("ii = %3.3d -- jj = %3.3d -- kk = %3.3d\n",ii,jj,kk);
	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);
}
int my_fork(void) {
	int ii;
	sleep(1);
	ii=(int) fork();
	sleep(1);
	return ii;
}

