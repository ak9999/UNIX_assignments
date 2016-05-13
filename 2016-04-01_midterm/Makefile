# Abdullah Khan

# Compile and compiler flags:
CC = cc
CFLAGS = -Wall -std=c11 -pedantic

all:
	make cracker
	make printer

cracker:
	$(CC) shadow_cracker.c -lcrypt -o cracker $(CFLAGS)

printer:
	$(CC) shadow_printer.c -o printer $(CFLAGS)

clean:
	(rm -f *.o;)
	(rm -f *.out;)
	(rm -f cracker;)
	(rm -f printer;)
