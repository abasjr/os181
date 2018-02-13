/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Tue Oct  3 20:49:01 WIB 2017
 * REV01 Sun Oct 16 20:47:18 WIB 2016
 * START Tue Sep 20 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +CHR+ +ADDRESS + +POINTS TO+ \n"

/* Global Variables */
unsigned char   varchr0='a';
unsigned char   varchr1='b';
unsigned char   varchr2='c';
unsigned char   varchr3='d';
unsigned char*  ptrchr0=&varchr0;
unsigned char*  ptrchr1=&varchr1;
unsigned char*  ptrchr2=&varchr2;
unsigned char*  ptrchr3=&varchr3;
unsigned char** ptrptr0=&ptrchr0;
unsigned char** ptrptr1=&ptrchr1;
unsigned char** ptrptr2=&ptrchr2;
unsigned char** ptrptr3=&ptrchr3;
unsigned char*** ppptr0=&ptrptr0;

void main(void) {
   printf(HEAD1);
   printf("varchr0 = %#10X = %c %11p\n", varchr0, varchr0,  &varchr0);
   printf("varchr1 = %#10X = %c %11p\n", varchr1, varchr1,  &varchr1);
   printf("varchr2 = %#10X = %c %11p\n", varchr2, varchr2,  &varchr2);
   printf("varchr3 = %#10X = %c %11p\n", varchr3, varchr3,  &varchr3);
   printf("ptrchr0 = %10p  %14p   %8c\n", ptrchr0, &ptrchr0, *ptrchr0);
   printf("ptrchr1 = %10p  %14p   %8c\n", ptrchr1, &ptrchr1, *ptrchr1);
   printf("ptrchr2 = %10p  %14p   %8c\n", ptrchr2, &ptrchr2, *ptrchr2);
   printf("ptrchr3 = %10p  %14p   %8c\n", ptrchr3, &ptrchr3, *ptrchr3);
   printf("ptrptr0 = %10p  %14p   %8p\n", ptrptr0, &ptrptr0, *ptrptr0);
   printf("ptrptr1 = %10p  %14p   %8p\n", ptrptr1, &ptrptr1, *ptrptr1);
   printf("ptrptr2 = %10p  %14p   %8p\n", ptrptr2, &ptrptr2, *ptrptr2);
   printf("ptrptr3 = %10p  %14p   %8p\n", ptrptr3, &ptrptr3, *ptrptr3);
   printf(" ppptr0 = %10p  %14p   %8p\n",  ppptr0,  &ppptr0,  *ppptr0);
}

