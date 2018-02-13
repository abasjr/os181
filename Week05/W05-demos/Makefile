# REV00 Mon Oct  3 13:27:38 WIB 2016
# START Mon Oct  3 09:21:51 WIB 2016

CC=gcc

EXECS= \
	06-memory


all:  $(EXECS)


06-memory: 06-memory.c
	$(CC) 06-memory.c -o 06-memory -Xlinker  \
		-Map=06-memory.map

clean:
	rm -f ${EXECS} 
	rm -f *.map
 
