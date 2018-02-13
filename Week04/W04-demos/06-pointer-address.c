/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV04 Tue Oct  3 21:46:48 WIB 2017
 * REV02 Sun Oct 16 20:48:44 WIB 2016
 * START Fri Sep 23 15:25:44 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +++ +CHR+ +++ ADDRESS  +++ +PTS TO+\n"
#define HEAD2 "!!! !!!!! ptrcopy++; ptrcopy++; ptrcopy++; ... !!!!! !!!\n"

void main(void) {
   unsigned char   varchr0='a';
   unsigned char*  ptrchr0=&varchr0;
   unsigned char*  ptrcopy=(char *) &ptrchr0;
   printf(HEAD1);
   printf("varchr0 = %#14X = %c  %16p\n",   varchr0, varchr0,  &varchr0);
   printf("ptrchr0 = %14p   %19p %#8.2X\n", ptrchr0, &ptrchr0, *ptrchr0);

   printf(HEAD2);
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
   ptrcopy++;
   printf("ptrcopy = %14p   %19p %#8.2X\n", ptrcopy, &ptrcopy, *ptrcopy);
}

