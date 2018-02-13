/*
 * (c) 2013-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV00 Mon Sep 18 09:47:49 WIB 2017
 * START 2013
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
   printf("Process Identifier (PID) [%5.5d] -- Perent PID (PPID[%5.5d])\n", getpid(), getppid());
   sleep(1);
}

