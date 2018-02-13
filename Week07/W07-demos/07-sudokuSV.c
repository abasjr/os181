/*
 * (c) 2015 M. Anwar Ma'sum and R.M. Samik-Ibrahim
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * SSV: Sudoku Solution Validator 
 * REV02 Wed Nov  1 18:04:38 WIB 2017
 * REV01 Wed Nov  2 11:20:30 WIB 2016
 * REV00 Xxx Sep 29 XX:XX:XX UTC 2015
 */

#include <stdio.h> 
#include <pthread.h>
#include "99-myutils.h"
#define  V_THREADS 27

int   idSequence = 0;
sem_t sync;
char  result[3][9];
int   sudoku[9][9] = {   /* Check this 9x9 matrix */
   {5,3,4, 7,6,8, 9,1,2},
   {6,9,2, 1,9,5, 3,4,8},
   {1,9,8, 3,4,2, 5,6,7},

   {8,5,9, 6,7,1, 4,2,3},
   {4,2,6, 8,5,3, 7,9,1},
   {7,1,3, 9,2,4, 8,5,6},

   {9,6,1, 5,3,7, 2,8,4},
   {2,8,7, 4,1,9, 6,3,5},
   {3,4,5, 2,8,6, 1,7,9}
};

char validate(int iINIT,int iEND,int jINIT,int jEND) {
   int  ii, jj;
   char flag[9];

   for (ii = 0; ii < 9; ii++) flag[ii] = 'F';
   for (ii = iINIT; ii < iEND; ii++) {
      for (jj = jINIT; jj < jEND; jj++) {
         if (flag[sudoku[ii][jj]-1] == 'F')
             flag[sudoku[ii][jj]-1] =  'T';
         else
             return 'F';
      }
   }
   return 'T';
}

void *sudokuValidator (void *param) {       
    int my_ID, tmp0, tmp1;
    char check;

    sem_wait(&mutex);
    my_ID = idSequence++;
    sem_post(&mutex);

    if (my_ID < 9) {
        check = validate (my_ID, my_ID+1, 0, 9);
    } else if (my_ID < 18) {
        check = validate (0,9,my_ID%9,my_ID%9+1);
    } else {
        tmp0  = ((my_ID%9)/3)*3;
        tmp1  = ((my_ID%9)%3)*3;
        check = validate (tmp0,tmp0+3,tmp1,tmp1+3);
    }

    sem_wait(&mutex);
    result[(my_ID/9)][(my_ID%9)] = check;
    sem_post(&mutex);
    sem_post(&sync);
}

void *reporter (void *p) {
   int ii,jj;
   for (ii = 0; ii < V_THREADS; ii++)
      sem_wait(&sync);
   for (ii = 0; ii < 3; ii++) {
      if      (ii == 0) printf ("ROW Validators: ");
      else if (ii == 1) printf ("COL Validators: ");
      else              printf ("BOX Validators: "); 
      for (jj = 0; jj < 9; jj++)
         printf("%c ", result[ii][jj]);
      printf("\n");
   }
}

void main(void *v) {
   int ii, jj;
   printf("SSV: Sudoku Solution Validator\n\n");
   for (ii=0; ii<9; ii++) {
      for (jj=0; jj<9; jj++) {
         printf("%d ", sudoku[ii][jj]);
         if ((jj%3) == 2)
            printf(" ");
      }
      printf ("\n");
      if ((ii%3) == 2)
         printf("\n");
   }
   sem_init(&mutex,0,1);
   sem_init(&sync, 0,0); 
   daftar_trit(reporter);
   for (ii = 0; ii < V_THREADS; ii++)
      daftar_trit(sudokuValidator);
   jalankan_trit();
   beberes_trit("Done...");
}

