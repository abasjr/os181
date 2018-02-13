# (c) 2007-2017 Rahmat M. Samik-Ibrahim
# http://rahmatm.samik-ibrahim.vlsm.org/
# This is free software. Feel free to copy and / or 
# modify and/or distribute it, provided this notice, 
# and the copyright notice, are preserved. 

# REV03 Fri Nov 10 17:59:12 WIB 2017
# REV01 Tue Nov  8 12:00:27 WIB 2016
# START Fri Mar 30 02:13:01 UTC 2007

CC=gcc
CFLAGS=-std=gnu99
DEPS=Makefile

EXECS= \
      00-server \
      01-client \
      02-clisvr \


all:	$(EXECS)


$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f $(EXECS)

