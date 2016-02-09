/*
 * Modified by: Abdullah Khan
 * Date: 2016-02-08
 * Program: bookeditor.c
 * Build instructions: make
 */
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
    if(argc != 3)
    {
        printf("Usage: editor FILE line_number\n");
        exit(1);
    }

    off_t curr_byte;
    ssize_t num_bytes;

    char buffer[200];
    int row = atoi(argv[2]);
    char * path_name = argv[1];
    int file_desc = open(path_name, O_CREAT|O_RDWR);

    // Get user's record
    char user_record[80];
    printf("Enter the record you would like to enter: ");
    scanf("%79s", user_record);

    // 0 bytes from current offset to find current offset
    curr_byte = lseek(file_desc, 0, SEEK_SET);
    printf("Cursor is at the %ldth byte.\n", curr_byte);

    // 0 bytes from EOF to find the number of bytes in file
    num_bytes = lseek(file_desc, 0, SEEK_END);
    printf("Cursor is at the %zdth byte.\n", num_bytes);

    // 0 bytes from current offset to find current offset
    curr_byte = lseek(file_desc, 0, SEEK_SET);
    printf("Cursor is at the %ldth byte.\n", curr_byte);

    // Read file contents, knowing total bytes in the file.
    ssize_t read_bytes = read(file_desc, buffer, num_bytes);
    printf("Reading %zd bytes.\n", read_bytes);
	printf("Reading --->%s<---.\n", buffer);

	// Output the contents of buffer onto terminal.
	ssize_t written_bytes = write(1, buffer, read_bytes);
	printf("Writing %zd bytes.\n", written_bytes);
	printf("Writing --->%s<---.\n", buffer);

	// Get the byte # at beginning of specified row
	off_t b = (off_t) getBytePos(row, file_desc);
	printf("Byte number at row %d is %ld.\n", row, b);

	putChar(file_desc, '\n', b);
	putChar(file_desc, 'X', b+1);

	return 0;
}

// Returns the byte # at the beginning of specified row #
int getBytePos(int row, int fd)
{
	printf("In getBytePosition()...\n");
	char buf[200];
	int i;

	// Find the total number of bytes in file
	off_t num_bytes = lseek(fd, 0, SEEK_END);
	printf("num_bytes = %zd\n", num_bytes);

	// IMPORTANT! Bring cursor back to BOF
	lseek(fd, 0, SEEK_SET);
	ssize_t read_bytes = read(fd, buf, num_bytes);
	printf("read_bytes = %zd\n", read_bytes);
	int num_rows = 1;

	// Loop goes through the number of bytes in the file
	for (i = 0; i < num_bytes; i++)
	{
		printf("buf[%d]=%c\n", i, buf[i]);
		// On EOL character, we increment the row #
		if (buf[i] == '\n')
		{
			printf("***EOL\n");
			num_rows++;
			// If row # equals row specified, ret. byte #
			if (num_rows == row)
			return i;
		}
	}
	return -1;
}

// Writes a character into a file at specified byte
void putChar(int fd, char c, off_t byte)
{
	lseek(fd, byte, SEEK_SET);
	// The write starts at the current offset
	write(fd, &c, 1);
}
