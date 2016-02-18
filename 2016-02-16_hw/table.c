/*
 * Author: Abdullah Khan
 * Date: 2016-02-16
 * Program: table.c
 * Description: Prints all info from stat structure of a file
    into a neat formatted table.
 * Build instructions: make
 */

#include <stdio.h> /* For standard input and output functions. */
#include <stdlib.h> /* For exit() */
#include <sys/stat.h> /* For mode_t */
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        printf("Usage: %s \"FILE\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat file_status;
    if(stat(argv[1], &file_status) < 0)
    {
        exit(EXIT_FAILURE);
    }

    printf("File status for: %s\n", argv[1]);
    printf("---------------------------\n");
    printf("Size: \t\t\t%lu bytes\n",file_status.st_size);
    printf("# of Links: \t\t\t%lu\n",file_status.st_nlink);
    printf("File inode: \t\t%lu\n",file_status.st_ino);

    printf("File Permissions: \n");
    printf((S_ISDIR(file_status.st_mode)) ? "1" : "0");
    printf(": directory\n");

    printf((file_status.st_mode & S_ISUID) ? "1" : "0");
    printf(": set-user-ID on execution\n");

    printf((file_status.st_mode & S_ISGID) ? "1" : "0");
    printf(": set-group-ID on execution\n");
    printf((file_status.st_mode & S_ISVTX) ? "1" : "0");
    printf(": saved-text (sticky bit)\n");

    printf((file_status.st_mode & S_IRWXU) ? "1" : "0");
    printf(": read, write, and execute by user (owner)\n");

    printf((file_status.st_mode & S_IRUSR) ? "1" : "0");
    printf(": read by user (owner)\n");

    printf((file_status.st_mode & S_IWUSR) ? "1" : "0");
    printf(": write by user (owner)\n");

    printf((file_status.st_mode & S_IXUSR) ? "1" : "0");
    printf(": execute by user (owner)\n");

    printf((file_status.st_mode & S_IRWXG) ? "1" : "0");
    printf(": read, write, and execute by group\n");

    printf((file_status.st_mode & S_IRGRP) ? "1" : "0");
    printf(": read by (group)\n");

    printf((file_status.st_mode & S_IWGRP) ? "1" : "0");
    printf(": write by (group)\n");

    printf((file_status.st_mode & S_IXGRP) ? "1" : "0");
    printf(": execute by (group)\n");

    printf((file_status.st_mode & S_IRWXO) ? "1" : "0");
    printf(": read, write, and execute by other (world)\n");

    printf((file_status.st_mode & S_IROTH) ? "1" : "0");
    printf(": read by other (world)\n");

    printf((file_status.st_mode & S_IWOTH) ? "1" : "0");
    printf(": write by other (world)\n");

    printf((file_status.st_mode & S_IXOTH) ? "1" : "0");
    printf(": execute by other (world)\n");

    printf("\n");

    exit(0);
}
