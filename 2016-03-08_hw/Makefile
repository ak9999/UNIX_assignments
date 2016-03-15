# Abdullah Khan

# Compile and compiler flags:
CC = cc
CFLAGS = -Wall -std=c11 -pedantic
DEBUG = -g

all:
	make find_users
	make group_names

find_users:
	$(CC) find_users.c -o get_users $(CFLAGS)

group_names:
	$(CC) group_names.c -o get_groups $(CFLAGS)

clean:
	(rm -f *.o;)
	(rm -f *.out;)
	(rm -f get_groups;)
	(rm -f get_users;)
