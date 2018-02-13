/*
 * (c) 2012-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Wed Nov  1 17:22:23 WIB 2017
 * REV01 Wed Nov  2 11:20:30 WIB 2016
 * REV00 Xxx Sep 30 XX:XX:XX UTC 2015
 * START Xxx Mar 30 02:13:01 UTC 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

#define lamaRehat  250
#define jmlPembalap 12
sem_t start;

void* bandar (void* a) {
   for (int ii=0; ii<jmlPembalap; ii++)
      sem_wait (&start);
   sem_wait (&mutex);
   sleep(2);
   rehat_acak(lamaRehat);
   printf ("Bandar Siap!\n");
   fflush(NULL);
   sem_post (&mutex);
}

int idmaster = 1;
int juara = 1;
int menang = TRUE;
void* pembalap (void* a) {
   int id;
   sem_wait (&mutex);
   id = idmaster++;
   sem_post (&mutex);
   sem_post (&start);
   rehat_acak(lamaRehat);
   printf ("Pembalap %2.2d Siap!\n",id);
   fflush(NULL);
   rehat_acak(lamaRehat);
   rehat_acak(lamaRehat);
   sem_wait (&mutex);
   if (menang==TRUE) printf("HORE, pemain");
   else printf("Aduh, pemain");
   printf(" %2.2d juara %2.2d!\n",id,juara++);
   menang = FALSE;
   sem_post (&mutex);
}

void main(void) {
   sem_init (&mutex, 0, 1);
   sem_init (&start, 0, 0);
   daftar_trit (bandar);
   for (int ii=0; ii<jmlPembalap; ii++)
      daftar_trit (pembalap);
   jalankan_trit ();
   beberes_trit ("Selese...");
}

