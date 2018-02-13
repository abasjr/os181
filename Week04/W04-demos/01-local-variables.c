/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Tue Oct  3 19:12:30 WIB 2017
 * REV01 Sun Oct 16 20:46:15 WIB 2016
 * START Tue Sep 20 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE  +++  VALUE +CHR+ +++  ADDRESS +++\n"

void main(void) {
   /* Local Variables in Stack Segment */
   unsigned char varchr0='a';
   unsigned char varchr1='b';
   unsigned char varchr2='c';
   unsigned char varchr3='d';
   unsigned char varchr4='e';
   unsigned char varchr5='f';
   unsigned char varchr6='g';
   unsigned char varchr7='h';

   printf(HEAD1);
   printf("varchr0 = %#10X = %c %17p\n", varchr0, varchr0, &varchr0);
   printf("varchr1 = %#10X = %c %17p\n", varchr1, varchr1, &varchr1);
   printf("varchr2 = %#10X = %c %17p\n", varchr2, varchr2, &varchr2);
   printf("varchr3 = %#10X = %c %17p\n", varchr3, varchr3, &varchr3);
   printf("varchr4 = %#10X = %c %17p\n", varchr4, varchr4, &varchr4);
   printf("varchr5 = %#10X = %c %17p\n", varchr5, varchr5, &varchr5);
   printf("varchr6 = %#10X = %c %17p\n", varchr6, varchr6, &varchr6);
   printf("varchr7 = %#10X = %c %17p\n", varchr7, varchr7, &varchr7);
}

