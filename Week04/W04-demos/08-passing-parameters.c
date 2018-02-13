/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Mon Oct  2 16:20:12 WIB 2017
 * REV02 Sun Oct 16 20:49:25 WIB 2016
 * START Tue Sep 27 10:43:40 WIB 2016
 */

#define NOP()    __asm__("nop")  /* No Operation inline gcc ASM *** */

#include <stdio.h>

int  varInt1   = 0x01;
int  varInt2   = 0x02;
int* ptrInt1   = &varInt1;
int* ptrInt2   = &varInt2;

/* ******************************************************************** */

void function1(void) {
   NOP();
}

/* ******************************************************************** */

void function2(int iif2) {
   printf("function2:     iif2 = %d\n", ++iif2);
}

/* ******************************************************************** */

void function3(int* iif3) {
   printf("function3:     iif3 = %d\n", ++(*iif3));
}

/* ******************************************************************** */

int  function4(void) {
   NOP();
}

/* ******************************************************************** */

int* function5(void) {
   NOP();
}

/* ******************************************************************** */

void main(void) {
   function1();
   printf("main-1:    *ptrInt1 = %d\n", *ptrInt1);
   function2(*ptrInt1);
   printf("main-2:    *ptrInt1 = %d\n", *ptrInt1);
   printf("main-3:     varInt1 = %d\n",  varInt1);
   function3(&varInt1);
   printf("main-4:     varInt1 = %d\n",  varInt1);
}

/* ******************************************************************** */
