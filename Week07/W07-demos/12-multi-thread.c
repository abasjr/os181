/*
 * (c) 2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * START Mon Nov 27 10:19:59 WIB 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"
#define  NTHREAD      4
#define  RECDEEP      2
#define  LOOP1  1000000
#define  LOOP2  1000000
#define  LOOP3  1000000

void  multiloop(int recursive) {
   int dummy;
   if (recursive-- < 0) return;
   for (int ii; ii<LOOP1; ii++) {
      for (int jj; jj<LOOP2; jj++) {
         for (int kk; kk<LOOP1; kk++) {
            dummy=ii*jj*kk;
         }
      }
   }
   multiloop(recursive);
}

void* thread (void* a) {
   printf("Start Thread...\n");
   multiloop(RECDEEP);
   printf("Stop  Thread...\n");
}

void main(void) {
   printf("This is MAIN\n");
   for (int ii=0;ii<NTHREAD;ii++)
      daftar_trit  (thread);
   jalankan_trit ();
   beberes_trit  ("TREXIT!");
}

