/*
 * Author: Abdullah Khan
 * Date: 2016-01-30
 * Program: save_name.c
 * Description: save_name takes an input from stdin (standard input).
 * Build instructions: make
 */

#include <fcntl.h> /* For creating, reading, and writing to files. */
#include <stdio.h> /* For standard input and output functions. */
#include <stdlib.h> /* For exit() */
#include <unistd.h> /* POSIX API */
#include <string.h> /* For string functions. */
#include <sys/stat.h> /* For mode_t */

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        printf("Usage: %s \"name\"\n", argv[0]);
        exit(1);
    }

    /* Copy the name to sized buffer; Overflow safe. */
    int name_size = strlen(argv[1]);
    char name[name_size];
    strncpy(name, argv[1], name_size);

    /* Set file permission mode.
     * S_IRUSR: Read permission for file owner.
     * S_IWUSR: Write permission for file owner.
     * S_IRGRP: Read permission for group.
     * S_IROTH: Read permission for other.
     */
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    /* Create file. */
    /* O_WRONLY: Open for write only.
     * O_CREAT: Create file if it doesn't already exist.
     * O_EXCL: If file already exists, open fails.
     */
    int file_desc = open("output.txt", O_WRONLY | O_CREAT | O_EXCL, mode);

    /* Check if open was successful, if not, exit. */
    if(file_desc == -1)
    {
        printf("Couldn\'t open file. Exiting.\n");
        exit(1);
    }

    /* Finally write the name to the file. */
    write(file_desc, name, name_size);
    //printf("Writing name to %s", output_file);

    /* Close the file. */
    int close_success = close(file_desc);
    if(close_success != 0)
    {
        printf("Error closing file.\n");
        exit(1);
    }
    exit(0);
}
