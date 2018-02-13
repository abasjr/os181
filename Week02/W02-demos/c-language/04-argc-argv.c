/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV01 Mon Sep 18 09:16:59 WIB 2017
 * START Tue Sep 13 12:11:09 WIB 2016
 */

#include <stdio.h>
void main(int argc, char *argv[]) {
   int ii;
   printf("The value of argc    is %d\n", argc);
   printf("=============================================\n");
   for (ii=argc-1; ii >= 0; ii--) {
      printf("The value of argv[%d] is %s\n", ii, argv[ii]);
   }
   printf("=============================================\n");
}

