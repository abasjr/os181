#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "99-myutils.h"
#define WaitSudoku 3
#define SSIZE 4
#define TOTALSIZE SSIZE * SSIZE

int     globalExit=FALSE;
sem_t   mutexing;
sem_t   syncing1;
sem_t   syncing2;

int cellSudoku[][SSIZE+1][SSIZE+1]={
    {},{{}, {0,1,2,3,4}, {0,1,2,3,4},
    {0,1,2,3,4}, {0,1,2,3,4}},
    {{}, {0,1,2,3,4}, {0,1,2,3,4},
    {0,1,2,3,4}, {0,1,2,3,4}},
    {{}, {0,1,2,3,4}, {0,1,2,3,4},
    {0,1,2,3,4}, {0,1,2,3,4}},
    {{}, {0,1,2,3,4}, {0,1,2,3,4},
    {0,1,2,3,4}, {0,1,2,3,4}}
};

void printCells(char* state){
    printf ("\nSudoku Cells:%s\n", state);
    for(int jj=1; jj<SSIZE+1; jj++){
        for(int kk=1; kk<SSIZE+1; kk++){
            int cell=cellSudoku[jj][kk][0];
            if (cell == 0 || cell == 5)
                            printf ("[]");
            else    printf("[%d]", cell);
            if(kk == SSIZE)printf("\n");
        }
    }
    fflush(NULL);
    
}
void
fillCell(int rowCell, int colCell, int valCell)
{
    sem_wait (&mutexing);
    cellSudoku[rowCell][colCell][0] = valCell;
    for (int ii=1; ii<SSIZE+1; ii++){
        cellSudoku[rowCell][colCell][ii] = 0;
    }
    
    for (int ii=1; ii<SSIZE+1; ii++){
        cellSudoku[rowCell][ii][valCell] = 0;
    }
    for (int ii=1; ii<SSIZE+1; ii++){
        cellSudoku[ii][colCell][valCell] = 0;
    }
    rowCell = 1 + 2*((rowCell - 1)/2);
    colCell = 1 + 2*((colCell - 1)/2);
    for (int ii=rowCell; ii<rowCell+2; ii++){
        for (int jj=colCell; jj<colCell+2; jj++){
            cellSudoku[ii][jj][valCell] = 0;
        }
    }
    sem_post (&mutexing);
}

 // CellWatcher
int cwID = 0;
void* cellWatcher (void* a) {
    sem_wait (&syncing1);
    sem_wait (&mutexing);
    int rowCell = cwID/4 + 1;
    int colCell = cwID%4 + 1;
    cwID++;
    sem_post (&mutexing);
    int localExit=FALSE;
    while (!localExit && !globalExit) {
        int tmpCell=0, nZero=0;
        for (int ii=1; ii<SSIZE+1; ii++) {
            if(cellSudoku[rowCell][colCell][ii]==0)
                nZero++;
            else
                tmpCell=ii;
            
        }
        if (nZero==3)
            fillCell(rowCell, colCell, tmpCell);
        localExit =
            cellSudoku[rowCell][colCell][0]!=0;
        
    }
    fflush(NULL);
    sem_post (&syncing2);
}

// Timeout after "WaitSudoku"
void* managerSudoku (void* a) {
    sleep(WaitSudoku);
    for (int ii=0; ii<TOTALSIZE; ii++) {
        int rowCell = ii/4 + 1;
        int colCell = ii%4 + 1;
        if(cellSudoku[rowCell][colCell][0]==0){
            cellSudoku[rowCell][colCell][0]= 5;
            
        }
        sem_post (&syncing2);
        
    }
    globalExit = TRUE;
}

// Display Sudoku
void* displaySudoku (void* a) {
    printCells("INITIAL");
    for(int jj=0;jj<TOTALSIZE;jj++)
        sem_post(&syncing1);
    for(int jj=0;jj<TOTALSIZE;jj++)
        sem_wait(&syncing2);
    printCells("RESULT");
}

// This is MAIN
void main(void) {
    printf ("MAIN: START\n");
    sem_init (&mutexing, 0, 1);
    sem_init (&syncing1, 0, 0);
    sem_init (&syncing2, 0, 0);
    inputCell();
    for (int ii=0; ii<TOTALSIZE; ii++) {
        daftar_trit(cellWatcher);
    }
    daftar_trit (displaySudoku);
    daftar_trit (managerSudoku);
    jalankan_trit ();
    beberes_trit ("\nTRIT: EXIT");
}
