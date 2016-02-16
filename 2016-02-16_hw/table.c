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

    printf("File Permissions: \t");
    printf((S_ISDIR(file_status.st_mode)) ? "1" : "0");

    printf((file_status.st_mode & S_ISUID) ? "1" : "0");
    printf((file_status.st_mode & S_ISGID) ? "1" : "0");
    //printf((file_status.st_mode & S_ISVTX) ? "1" : "0");

    //printf((file_status.st_mode & S_ISWXU) ? "1" : "0");
    printf((file_status.st_mode & S_IRUSR) ? "1" : "0");
    printf((file_status.st_mode & S_IWUSR) ? "1" : "0");
    printf((file_status.st_mode & S_IXUSR) ? "1" : "0");

    //printf((file_status.st_mode & S_ISWXG) ? "1" : "0");
    printf((file_status.st_mode & S_IRGRP) ? "1" : "0");
    printf((file_status.st_mode & S_IWGRP) ? "1" : "0");
    printf((file_status.st_mode & S_IXGRP) ? "1" : "0");

    printf((file_status.st_mode & S_IRWXO) ? "1" : "0");
    printf((file_status.st_mode & S_IROTH) ? "1" : "0");
    printf((file_status.st_mode & S_IWOTH) ? "1" : "0");
    printf((file_status.st_mode & S_IXOTH) ? "1" : "0");

    printf("\n");

    exit(0);
}
