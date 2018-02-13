/*
 * (c) 2015-2017 Rahmat M. Samik-Ibrahim -- This is free software
 * REV05 Mon Oct  2 16:24:45 WIB 2017
 * REV04 Thu Mar  9 21:22:36 WIB 2017
 * REV02 Sun Oct 16 20:52:15 WIB 2016
 * START Xxx Apr 25 XX:XX:XX WIB 2015
 *
 * dup(fd) duplicates fd
 * fd2=dup(fd1)  <---> dup2(fd1, fd2)
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FILE1 "demo-file8.txt"

static char* str1 = "AAAXBBB\n";
static char* str2 = "CCC\n";

void main(void) {
   int fd1, fd2;
   fd1 = open (FILE1, O_RDWR | O_CREAT, 0644);
   dup2(fd1, fd2);
   printf("File Descriptors --- fd1 = %d, fd2 = %d\n", fd1, fd2);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
   close(fd1);
   close(fd2);
   printf("**** Please check file %s *****\n", FILE1);
   printf("**** Compare with 54-write\n");
}

