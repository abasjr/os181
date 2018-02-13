/*
 * (c) 2011-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Tue Nov  7 19:59:38 WIB 2017
 * REV01 Wed Nov  2 11:20:30 WIB 2016
 * REV00 Xxx Sep 30 XX:XX:XX UTC 2012
 * START Xxx Mar 30 02:13:01 UTC 2011
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"

#define P_REHAT 2000
#define K_REHAT 2000
int produk = 0;

void* Produsen (void* a) {
   printf("Produsen siap...\n");
   while (TRUE) {
      printf("P: REHAT ******\n");
      rehat_acak(P_REHAT);
      printf("P: PRODUKSI %d\n", produk);
      enter_buffer  (produk++);
   }
}

void* Konsumen (void* a) {
   printf   ("                        Konsumen siap...\n");
   while (TRUE) {
      printf("                        K: REHAT ******\n");
      rehat_acak(K_REHAT);
      printf("                        K: KONSUMSI %d\n", remove_buffer());
   }
}

int main(int argc, char * argv[])
{
   init_buffer();
   daftar_trit(Produsen);
   daftar_trit(Konsumen);
   jalankan_trit();
   beberes_trit("Selese...");
}

