/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV04 Tue Oct  3 21:18:21 WIB 2017
 * REV02 Sun Oct 16 20:48:01 WIB 2016
 * START Tue Sep 20 17:00:52 WIB 2016
 */

#include <stdio.h>

#define HEAD1 "VARIABLE  +++  VALUE +CHR+ +ADDRESS + +POINTS TO+++\n"
#define HEAD2 "!!! ptrint0=(int*) &varchr1;  varint0=*ptrint0; !!!\n"
#define HEAD4 "!!! ptrchr0=(char*) &varint0; varchr0=*ptrchr0; !!!\n"
#define HEAD5 "!!!! !!!!  ptrchr0++;  varchr0=*ptrchr0;  !!!! !!!!\n"

/* Global Variables */
unsigned int    varint0=0x41424344;
unsigned char   varchr0='a';
unsigned char   varchr1='b';
unsigned char   varchr2='c';
unsigned char   varchr3='d';
unsigned char   varchr4='e';

unsigned int*   ptrint0=&varint0;
unsigned char*  ptrchr0=&varchr0;

void main(void) {
   printf(HEAD1);
   printf("varint0 = %#10X = %c  %10p\n", varint0, varint0,  &varint0);
   printf("varchr0 = %#10X = %c %11p\n", varchr0, varchr0,  &varchr0);
   printf("varchr1 = %#10X = %c %11p\n", varchr1, varchr1,  &varchr1);
   printf("varchr2 = %#10X = %c %11p\n", varchr2, varchr2,  &varchr2);
   printf("varchr3 = %#10X = %c %11p\n", varchr3, varchr3,  &varchr3);
   printf("ptrint0 = %10p  %14p %12X\n", ptrint0, &ptrint0, *ptrint0);
   printf("ptrchr0 = %10p  %14p %12c\n",  ptrchr0, &ptrchr0, *ptrchr0);
   printf(HEAD2);
   ptrint0=(int*) &varchr1;
   varint0=*ptrint0;
   printf(HEAD1);
   printf("ptrint0 = %10p %14p %#12X\n", ptrint0, &ptrint0, *ptrint0);
   printf("varint0 = %#10X = %c %10p\n", varint0, varint0, &varint0);
   printf(HEAD4);
   ptrchr0=(char*) &varint0; 
   varchr0=*ptrchr0;
   printf(HEAD1);
   printf("ptrchr0 = %10p %14p %#12X\n", ptrchr0, &ptrchr0, *ptrchr0);
   printf("varchr0 = %#10X = %c %10p\n", varchr0, varchr0, &varchr0);
   printf(HEAD5);
   ptrchr0++;
   varchr0=*ptrchr0;
   printf(HEAD1);
   printf("ptrchr0 = %10p %14p %#12X\n", ptrchr0, &ptrchr0, *ptrchr0);
   printf("varchr0 = %#10X = %c %10p\n", varchr0, varchr0, &varchr0);
}

