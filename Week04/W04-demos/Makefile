# REV06 Thu Oct  5 11:04:52 WIB 2017
# REV03 Thu Mar  9 21:18:27 WIB 2017
# START Tue Sep 13 11:44:18 WIB 2016

CC=gcc

P00=00-global-variables
P01=01-local-variables
P02=02-pointers
P03=03-pointers-of-pointers
P04=04-pointers-of-pointers-of-pointers
P05=05-chrptr-vs-intptr
P06=06-pointer-address
P07=07-addresses
P08=08-passing-parameters
P09=09-struct
P50=50-get-put
P51=51-get-put-loop
P52=52-open-close
P53=53-file-pointer
P54=54-write
P55=55-write
P56=56-copy
P57=57-dup
P58=58-dup2
P59=59-io
P60=60-readwrite


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
        $(P50) \
        $(P51) \
        $(P52) \
        $(P53) \
        $(P54) \
        $(P55) \
        $(P56) \
        $(P57) \
        $(P58) \
        $(P59) \
        $(P60) \


DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file4.txt \
	demo-file5.txt \
	demo-file6.txt \
	demo-file7.txt \
	demo-file8.txt \
	demo-file9.txt \
	demo-fileA.txt \
	demo-copy.txt  \


all:  $(EXECS)

$(P00): $(P00).c
	$(CC) $(P00).c -o $(P00) -Xlinker -Map=$(P00).map

$(P01): $(P01).c
	$(CC) $(P01).c -o $(P01) -Xlinker -Map=$(P01).map

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
	$(CC) $(P07).c -o $(P07) -Xlinker -Map=$(P07).map

$(P08): $(P08).c
	$(CC) $(P08).c -o $(P08)

$(P09): $(P09).c
	$(CC) $(P09).c -o $(P09)

$(P50): $(P50).c
	$(CC) $(P50).c -o $(P50)

$(P51): $(P51).c
	$(CC) $(P51).c -o $(P51)

$(P52): $(P52).c
	$(CC) $(P52).c -o $(P52)

$(P53): $(P53).c
	$(CC) $(P53).c -o $(P53)

$(P54): $(P54).c
	$(CC) $(P54).c -o $(P54)

$(P55): $(P55).c
	$(CC) $(P55).c -o $(P55)

$(P56): $(P56).c
	$(CC) $(P56).c -o $(P56)

$(P57): $(P57).c
	$(CC) $(P57).c -o $(P57)

$(P58): $(P58).c
	$(CC) $(P58).c -o $(P58)

$(P59): $(P59).c
	$(CC) $(P59).c -o $(P59)

$(P60): $(P60).c
	$(CC) $(P60).c -o $(P60)

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh

