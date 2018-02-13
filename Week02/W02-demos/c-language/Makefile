# REV02 Mon Sep 18 09:08:32 WIB 2017
# START Tue Sep 13 11:44:18 WIB 2016

CC=gcc

EXECS= \
	00-hallo \
	01-hallo \
	02-variables \
	03-loop \
	04-argc-argv \
	05-envp \
	06-scan \
	07-status \


all:  $(EXECS)

00-hallo: 00-hallo.c
	$(CC) -o 00-hallo 00-hallo.c

01-hallo: 01-hallo.c
	$(CC) -o 01-hallo 01-hallo.c

02-variables: 02-variables.c
	$(CC) -o 02-variables 02-variables.c

03-loop: 03-loop.c
	$(CC) -o 03-loop 03-loop.c

04-argc-argv: 04-argc-argv.c
	$(CC) -o 04-argc-argv 04-argc-argv.c

05-envp: 05-envp.c
	$(CC) -o 05-envp 05-envp.c

06-scan: 06-scan.c
	$(CC) -o 06-scan 06-scan.c

07-status: 07-status.c
	$(CC) -o 07-status 07-status.c

clean:
	rm -f ${EXECS}

