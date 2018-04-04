#include <stdio.h>   /*standard I/O */
#include <unistd.h>  /*fork() system call yang berfungsi untuk membuat proses baru*/
#include <sys/types.h> /*pid_t = Process Identifier (Uniq)*/
#include <stdlib.h>
#include <sys/wait.h> /*wait = untuk wait*/

int main ()
{
	pid_t pid;
	pid = fork();

	if (pid <0) 
	{
		//terjadi error
		fprintf(stderr,"Fork Gagal");
		exit(-1);
	}
	else if (pid==0) 
	{
		//child process
		execlp("/bin/ls","ls",NULL);
	}
	else
	{
		//parent process
		wait(NULL);
		printf("Child Process selesai\n");
		exit(0);
	}
}

