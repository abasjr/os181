/*
 * (c) 2005-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV02 Mon Oct  2 16:25:44 WIB 2017
 * REV01 Sun Oct 16 20:53:09 WIB 2016
 * START Xxx Xxx XX XX:XX:XX WIB 2005
 */

#define FILE1 "demo-fileA.txt"

#define  OLOOP 10
#define  ILOOP 3650
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

void rwfile (char* fname);
void dirfile(char* dname);
void error  (char* msg);

/* MAIN ============================= */
void main(void) {
   printf("Listing current directory...\n");
   dirfile(".");
   printf("Testing read-write speed...\n");
   rwfile(FILE1);
}
/* DIRFILE ======================= */
void dirfile(char* dname) {
   DIR*            ddir;
   struct dirent*  dp;
   printf("     ");
   ddir = opendir(dname);
   if (ddir != NULL) {
      while ((dp=readdir(ddir))!= NULL)
         printf("%s  ", dp->d_name);
      closedir(ddir);
   }
   printf("\n\n");
}
/* ERROR ========================== */
void error(char* msg){
   perror(msg);
   exit(0);
}
/* RWFILE ========================== */
void rwfile(char* fname) {
   time_t tt;
   int    fd, ii, jj;
   char   buf[] = "Achtung... Achtung... AAAA BBBB CCCC DDDD\n";
   time(&tt);
   for (ii=0;ii<OLOOP;ii++) {
      if ((fd=creat(fname,00644)) < 0 )
         error("RWFILE: can not create file\n");
      for (jj=0;jj<ILOOP;jj++) {
         write(fd,buf,sizeof(buf)-1);
         fsync(fd);
      }
      close(fd);
      putchar('.');
      fflush(NULL);
   }
   tt=time(NULL)-tt;
   putchar('\n');
   printf("Total time: %d seconds\n", (int) tt);
}

