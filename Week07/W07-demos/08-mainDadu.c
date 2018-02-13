/*
 * (c) 2012-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Wed Nov  1 18:16:14 WIB 2017
 * REV01 Wed Nov  2 11:20:30 WIB 2016
 * REV00 Xxx Sep 30 XX:XX:XX UTC 2015
 * START Xxx Mar 30 02:13:01 UTC 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"

#define P_REHAT  400
#define K_REHAT 2000
#define WINpoint  12

sem_t	mutex1;
	
int	idmaster=0;
int	winner=0;

void* Dice (void* a) {
   int dadu;
   printf("The Dice is ready...\n");
   while (TRUE) {
      rehat_acak(P_REHAT);
      dadu=(random() % 6) + 1;
      printf("Dice value %d\n", dadu);
      enter_buffer  (dadu);
      if (winner !=0) {
         enter_buffer  (dadu);
         enter_buffer  (dadu);
         enter_buffer  (dadu);
         enter_buffer  (dadu);
         enter_buffer  (dadu);
         enter_buffer  (dadu);
         break;
      }
   }
}

void* Player (void* a) {
   int id, prev=0, total=0;
   sem_wait (&mutex1);
   id=idmaster++;
   sem_post (&mutex1);
   printf   ("                        Player %d is ready...\n",id);
   while (total < WINpoint) {
      rehat_acak(K_REHAT);
      prev   = total;
      total += remove_buffer();
      if (winner !=0) break;
      printf("                        Player %d's points: %2d [plus %d] \n", 
                                      id, total, total-prev);
   }
   if (winner != 1)
      printf("                        Player %d WINS!!!! (%d)\n", id, total);
   winner = 1;
   printf("                        Player %d EXIT\n", id);
}

int main(int argc, char * argv[]) {
   printf("The first player -- with more than %d points -- wins **** ****\n", WINpoint);
   sleep(1);
   sem_init (&mutex1, 0, 1);
   init_buffer();
   daftar_trit(Dice);
   daftar_trit(Player);
   daftar_trit(Player);
   daftar_trit(Player);
   daftar_trit(Player);
   daftar_trit(Player);
   jalankan_trit();
   beberes_trit("Done...");
}

