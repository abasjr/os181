/*
 * (c) 2013-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV01 Mon Sep 18 09:16:28 WIB 2017
 * START 2013
 */

#define LINETXT "==========\n"
#define OLOOPTXT "OL [%4.4d]\n"
#define OLOOP  4
#define ILOOP  3

#include <stdio.h>
void main() {
   int ii, jj;
   printf(LINETXT);
   for (ii=0; ii<OLOOP; ii++) {
      printf(OLOOPTXT, ii);
      for (jj=0; jj<ILOOP; jj++) {
         printf("    IL[%d]\n",jj);
      }
   }
   printf(LINETXT);
}

