# Assignment: Replace or insert row in file

## Assignment instructions:
Write a C program that replaces or inserts a row in the books.txt file. You can
specify your own row number as the row that needs to be replaced. You can supply
your own record (for instance, your favorite book and its author). The books.txt
file contains book records, each with two fields: a book title field (with no blank
spaces in it) and an author field (again, with no blank spaces in it). You should be
able to replace the record at the row number specified, with your own.

# What I added to the program:
Before the first write operation in editor.c:60, I added a lseek call to move
the cursor back one byte so we don't miss any bytes.
I also added a new function called putBuffer, which is similar to putChar except
it works for C-strings and writes the length of the user's input instead of 1 byte.

# What works:
The program will clobber which ever line you wish it to write.
If given a long enough input, the line will be deleted and the next line will be
moved up and overwritten with the user's input.

## Build instructions:
Run `make`. Your compiler must support C11.

## Running
Run editor FILE line_number to over-write that line in FILE.
