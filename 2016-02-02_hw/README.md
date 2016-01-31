# Assignment: Simple implementation of cp

## Assignment instructions:
Write a small system program that creates a file and writes your name in it,
taking your name as input from the command line. It should use the system
functions `creat()` and `write()`. For the synopsis of these functions, consult
section 2 of the `man` pages on your system. Then, adapt the ./mycp program from
earlier, to copy your newly created file into another file, without the redirect
operators. To do that, you need to pass the source and the target files as
command line arguments to your program.

## Build instructions:
Run `make`. Your compiler must support C11.

## Running
Run ./cp to copy anything and everything.
Run ./save_name "name" to save a name to a file output.txt
