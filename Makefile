# compiler
CC=gcc
# compiler flags
CFLAGS=-Wall -ansi -pedantic-errors
# link/load flags ex: "-lm" for math.h
LDFLAGS= -lm 

main:
	$(CC) $(CFLAGS) -o determinantcalc determinantcalc.c $(LDFLAGS)

clean:
	rm -rf determinantcalc

all:
	rm -rf determinantcalc
	$(CC) $(CFLAGS) $(LDFLAGS) -o determinantcalc determinantcalc.c
	sleep 0.25
	clear
	./determinantcalc