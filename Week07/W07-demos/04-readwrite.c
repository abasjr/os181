/*
 * (c) 2011-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV05 Tue Nov  7 20:07:45 WIB 2017
 * REV02 Fri Apr 28 10:06:07 WIB 2017
 * REV00 Xxx Sep 30 XX:XX:XX UTC 2015
 * START Xxx Mar 30 02:13:01 UTC 2011
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

sem_t           sync_er, sync_re, sync_ew, sync_we;

#define R_REHAT 1500
#define R_READ  1500
#define R_JUMLAH  2

#define W_REHAT 1500
#define W_WRITE 1500
#define W_JUMLAH  2

#define aReader 0
#define aWriter 1

void* Extra (void* a) {
   int ii;
   while (TRUE) {
      for (ii=0; ii<W_JUMLAH; ii++)
         sem_wait (&sync_we);
      for (ii=0; ii<R_JUMLAH; ii++)
         sem_post (&sync_er);
      for (ii=0; ii<R_JUMLAH; ii++)
         sem_wait (&sync_re);
      for (ii=0; ii<W_JUMLAH; ii++)
         sem_post (&sync_ew);
   }
}

void* Reader (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aReader);
   printf   ("                        READER %d: SIAP  ******\n", my_ID);
   while (TRUE) {
      sem_wait (&sync_er);
      printf("                        READER %d: REHAT ******\n", my_ID);
      rehat_acak(R_REHAT);
      printf("                        READER %d: MAU  MEMBACA\n", my_ID);
      printf("                        ***** JUMLAH PEMBACA %d\n", startRead());
      printf("                        READER %d:=SEDANG==BACA\n", my_ID);
      rehat_acak(R_READ);
      printf("                        READER %d: SELESAI BACA\n", my_ID);
      printf("                        ***** SISA PEMBACA %d\n", endRead());
      sem_post (&sync_re);
   }
}

void* Writer (void* a) {
   int  my_ID;

   my_ID = getADDglobalID(aWriter);

   printf   ("WRITER %d: SIAP  *******\n", my_ID);
   while (TRUE) {
      printf("WRITER %d: REHAT *******\n", my_ID);
      rehat_acak(W_REHAT);
      printf("WRITER %d: MAU   MENULIS\n", my_ID);
      startWrite();
      printf("WRITER %d:=SEDANG==NULIS\n", my_ID);
      rehat_acak(W_WRITE);
      endWrite();
      printf("WRITER %d: SELESAI NULIS\n", my_ID);
      sem_post (&sync_we);
      sem_wait (&sync_ew);
   }
}

int main(int argc, char * argv[])
{
   int ii;
   init_rw();
   init_globalID ();
   sem_init   (&sync_er, 0, 0);
   sem_init   (&sync_re, 0, 0);
   sem_init   (&sync_ew, 0, 0);
   sem_init   (&sync_we, 0, 0);
   daftar_trit(Extra);
   for (ii = 0 ; ii < R_JUMLAH; ii++)
      daftar_trit(Reader);
   for (ii = 0 ; ii < W_JUMLAH; ii++)
      daftar_trit(Writer);
   jalankan_trit();
   beberes_trit("Selese...");
}



