# Abdullah Khan

# Compiler and compiler flags

CC = cc
CFLAGS = -Wall -pedantic

all:
	make threads
	make daemon

threads:
	$(CC) threads.c -o threads.out $(CFLAGS)

daemon:
	$(CC) daemon.c -o daemon.out $(CFLAGS)

clean:
	(rm -f *.o;)
	(rm -f *.out;)
