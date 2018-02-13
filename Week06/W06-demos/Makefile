# REV04 Wed Nov  1 13:30:30 WIB 2017
# START Mon Oct 24 09:18:34 WIB 2016
# DEMOFILES=\
# 	demo-file1.txt \
# 	demo-file2.txt \

CC=gcc
 
P00=00-show-pid
P01=01-fork
P02=02-fork
P03=03-fork
P04=04-sleep
P05=05-fork
P06=06-fork
P07=07-fork
P08=08-fork
P09=09-fork
P10=10-fork
P11=11-fork
P12=12-fork
P14=14-fork
P15=15-fork

EXECS= \
	$(P00) \
	$(P01) \
	$(P02) \
	$(P03) \
	$(P04) \
	$(P05) \
	$(P06) \
	$(P07) \
	$(P08) \
	$(P09) \
	$(P10) \
	$(P11) \
	$(P12) \
	$(P14) \
	$(P15) \


all:	$(EXECS)

$(P00): $(P00).c
	$(CC) $(P00).c -o $(P00)

$(P01): $(P01).c
	$(CC) $(P01).c -o $(P01)

$(P02): $(P02).c
	$(CC) $(P02).c -o $(P02)

$(P03): $(P03).c
	$(CC) $(P03).c -o $(P03)

$(P04): $(P04).c
	$(CC) $(P04).c -o $(P04)

$(P05): $(P05).c
	$(CC) $(P05).c -o $(P05)

$(P06): $(P06).c
	$(CC) $(P06).c -o $(P06)

$(P07): $(P07).c
	$(CC) $(P07).c -o $(P07)

$(P08): $(P08).c
	$(CC) $(P08).c -o $(P08)

$(P09): $(P09).c
	$(CC) $(P09).c -o $(P09)

$(P10): $(P10).c
	$(CC) $(P10).c -o $(P10)

$(P11): $(P11).c
	$(CC) $(P11).c -o $(P11)

$(P12): $(P12).c
	$(CC) $(P12).c -o $(P12)

$(P14): $(P14).c
	$(CC) $(P14).c -o $(P14)

$(P15): $(P15).c
	$(CC) $(P15).c -o $(P15)

clean:
	rm -f $(EXECS)

