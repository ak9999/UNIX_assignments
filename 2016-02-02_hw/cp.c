/*
 * Author: Abdullah Khan
 * Date: 2016-01-30
 * Program: cp.c
 * Description: Simple implementation of cp
 * Build instructions: make
 */

#include <fcntl.h> /* For creating, reading, and writing to files. */
#include <stdio.h> /* For standard input and output functions. */
#include <stdlib.h> /* For exit() */
#include <unistd.h> /* POSIX API */
#include <sys/stat.h> /* For mode_t */

int main(int argc, char ** argv)
{
    if(argc != 3)
    {
        printf("Usage: cp SOURCE DEST\n");
        exit(1);
    }

    int source, dest; /* File descriptors. */

    /* Open source file as read-only. */
    source = open(argv[1], O_RDONLY, S_IRUSR);
    if(source == -1)
    {
        printf("Cannot open \'%s\': No such file\n", argv[1]);
        exit(1);
    }

    /* Create destination. */
    dest = open(argv[2], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if(dest == -1)
    {
        printf("Error while writing\n");
        exit(1);
    }

    const int BUFFERSIZE = 4096;
    ssize_t n;
    char buffer[BUFFERSIZE];

    while((n = read(source, buffer, BUFFERSIZE)) > 0 )
    {
        write(dest, buffer, n);
    }

    if(n < 0) { printf("Read error.\n"); }

    /* Close files. */
    close(source);
    close(dest);

    exit(0);
}
