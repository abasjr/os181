/*
 * (c) 2015-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV01 Mon Oct  2 16:23:50 WIB 2017
 * REV00 Tue Sep 27 18:41:32 WIB 2016
 * START Tue Apr 25 XX:XX:XX WIB 2015
 * USE "cmp file1 file2"
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define  BUF_SIZE 16

void main(int argc, char* argv[])
{
   int          fdread, fdwrite;
   unsigned int total_bytes = 0;
   ssize_t      nbytes_read, nbytes_write;
   char buf[BUF_SIZE];
   if (argc != 3) {
      printf("Usage: %s source destination\n",
      argv[0]);
      exit(1);
   }
   fdread = open(argv[1], O_RDONLY);
   if (fdread < 0) {
      perror("Failed to open source file");
      exit(1);
   }
   fdwrite = creat(argv[2], S_IRWXU);
   if (fdwrite < 0) {
      perror("Failed to open destination file");
      exit(1);
   }
   do {
      nbytes_read = read(fdread, buf, BUF_SIZE);
      if (nbytes_read < 0) {
         perror("Failed to read from file");
         exit(1);
      }
      nbytes_write = write(fdwrite, buf, nbytes_read);
      if (nbytes_write < 0) {
         perror("Failed to write to file");
         exit(1);
      }
   } while (nbytes_read > 0);
   close(fdread);
   close(fdwrite);
   exit(0);
}
 
