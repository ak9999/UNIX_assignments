# Abdullah Khan

# Compile and compiler flags:
CC = gcc
CFLAGS = -Wall -pedantic
DEBUG = -g

all:
	make chown_clone
	make table

chown_clone:
	$(CC) chown_clone.c -o chown_clone $(CFLAGS)

table:
	$(CC) table.c -o table $(CFLAGS)

clean:
	(rm -f *.o;)
	(rm -f *.out;)
	(rm -f chown_clone table;)
