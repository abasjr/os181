/*
 * (c) 2015-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV05 Wed Nov  1 19:51:21 WIB 2017
 * REV04 Tue Dec 13 15:19:04 WIB 2016
 * START Wed Sep 30 00:00:00 UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"
#define  nSem 7

sem_t	sem[nSem];

void* thread1 (void* a) {
   sem_wait   (&sem[1]);
   printf("T1X\n");
   sem_post   (&sem[4]);
}

void* thread2 (void* a) {
   sem_wait   (&sem[2]);
   printf("T2X\n");
   sem_post   (&sem[5]);
   sem_post   (&sem[1]);
}

void* thread3 (void* a) {
   printf("T3X\n");
   sem_post   (&sem[6]);
   sem_post   (&sem[2]);
}

void* thread4 (void* a) {
   sem_wait   (&sem[4]);
   printf("T44\n");
   sem_wait   (&sem[5]);
   printf("T45\n");
   sem_wait   (&sem[6]);
   printf("T46\n");
}

void main(void) {
   printf("MAIN\n");
   for (int ii=1;ii<nSem;ii++)
      sem_init(&sem[ii], 0, 0);
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   daftar_trit   (thread4);
   jalankan_trit ();
   beberes_trit  ("TREXIT");
}

