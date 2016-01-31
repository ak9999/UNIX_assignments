# Abdullah Khan

# Compile and compiler flags:
CC = gcc
CFLAGS = -Wall -std=c11 -pedantic
DEBUG =- g

all:
	make save_name
	make cp

save_name:
	$(CC) save_name.c -o save_name $(CFLAGS)

cp:
	$(CC) cp.c -o cp $(CFLAGS)

clean:
	(rm -f *.o;)
	(rm -f *.out;)
	(rm -f *.txt;)
	(rm -f save_name;)
	(rm -f cp;)
