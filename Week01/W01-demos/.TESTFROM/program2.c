/* REV02 Fri Sep  8 21:17:45 WIB 2017
 * START Mon Feb 13 20:22:22 WIB 2017
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * This is a free software.
 */
#define LOOP1 400
#define LOOP2 1000000
#include <stdio.h>

void main() {
   int ii, jj, kk=0;
   for (ii=0;ii<LOOP1;ii++) {
      for (jj=0;jj<LOOP2;jj++) {
         kk = kk + ii;
      }
   }
   printf("Result=%d\n",kk);
}
