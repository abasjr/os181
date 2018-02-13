/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV01 Mon Sep 18 09:18:43 WIB 2017
 * START Tue Sep 13 12:11:09 WIB 2016
 */

#include <stdio.h>
#include <string.h>
#define MAXLOOP 15
#define MAXLENG 60

void main(int argc, char *argv[], char **envp) {
   int ii;
   printf("===============================================================\n");
   for (ii=0; (ii < MAXLOOP ) && (envp[ii] != NULL) ; ii++) {
      if (strlen(envp[ii]) > MAXLENG) {
         envp[ii][MAXLENG-4] = 'X';
         envp[ii][MAXLENG-3] = 'X';
         envp[ii][MAXLENG-2] = 'X';
         envp[ii][MAXLENG-1] = '\0';
      }
      printf("The value of envp[%2.2d] is %s\n", ii, envp[ii]);
   }
   printf("===============================================================\n");
}

