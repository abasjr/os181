/*
 * (c) 2017 Rahmat M. Samik-Ibrahim -- This is free software
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * Adapted from University of Waterloo Midterm Winter 2012.
 * REV03 Wed Nov  1 13:32:11 WIB 2017
 * START Wed May  3 20:56:05 WIB 2017
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void waitAndPrintPID(void) {
   wait(NULL);
   printf("PID: %d\n", getpid());
   fflush(NULL);
}

void main(int argc, char *argv[]) {
   int rc, status;

   waitAndPrintPID();
   rc = fork();
   waitAndPrintPID();
   if (rc == 0) {
      fork();
      waitAndPrintPID();
      execlp("./00-show-pid", "00-show-pid", NULL);
   }
   waitAndPrintPID();
}

