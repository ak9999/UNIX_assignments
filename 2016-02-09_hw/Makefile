# Abdullah Khan

# Compile and compiler flags:
CC = gcc
CFLAGS = -Wall -std=c11 -pedantic
DEBUG = -g

all:
	make editor

editor:
	$(CC) editor.c -o editor.out $(CFLAGS)

debug:
	$(CC) editor.c -g -o dedit.out $(CFLAGS)

clean:
	(rm -f *.o;)
	(rm -f *.out;)
