#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int forkDelayChildAndAddLevel(int level) {
	if (! fork()) {
		level++;
	}
	sleep(level);
	return level;
}
void main() {
	int level = 0;
	level=forkDelayChildAndAddLevel(level);
	level=forkDelayChildAndAddLevel(level);
	level=forkDelayChildAndAddLevel(level);
	wait(NULL);
	wait(NULL);
	wait(NULL);
	printf("Level[%d]: PID[%d] (PPID[%d])\n",
			level, getpid(), getppid());
}
