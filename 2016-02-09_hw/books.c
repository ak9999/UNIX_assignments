#include <fcntl.h> // for open()
#include <sys/stat.h> // for file access permission bits
#include <stdio.h> // for FILENAME_MAX
#include <unistd.h> // for pathconf()
#include <string.h> // for strcat()
#include <stdlib.h> // for malloc()
#include <errno.h> // for errno

int getChar(int fd);
int getBytePos(int row, int fd);
void putChar(int fd, char c, off_t byte);

int main(int argc, char ** argv)
{
    off_t curr_byte;
    ssize_t num_bytes;
    char buffer[200];
    int row = 3;

    char * path_name = argv[1];
    int file_desc = open(path_name, O_CREAT|O_RDWR);

