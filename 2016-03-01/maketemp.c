/*
 * Author: Abdullah Khan
 * Date: 2016-02-23
 * Program: traverse.c
 * Description: Descends a file hierarchy and returns how many files of
 * each type there are, and what percentage of the total each type represents.
 * Build instructions: make
 */

/* If using a compiler that defaults to C99 or later */
#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif /* __STDC_VERSION__ */

// STDC includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // To get the current date and time.

// POSIX includes
#include <unistd.h>
#include <fcntl.h> // open()
#include <sys/stat.h> // for file permissions

int main(int argc, char ** argv)
{
	char tmp_template[] = "/tmp/temp.XXXXXX";
	int file_desc = mkstemp(tmp_template);
	printf("Temporary file %s created", tmp_template);
	printf("\n");

	/* Check if open was successful, if not, exit. */
    if(file_desc == -1)
    {
        printf("Couldn\'t open file. Exiting.\n");
        exit(EXIT_FAILURE);
    }

	// Our current date and time since the Epoch
	char buffer[100];
	time_t current = time(NULL);
	//struct tm *t = localtime(&current);
	//strftime(buffer, sizeof(buffer)-1, "%d %m %Y %H:%M", t);
	strncpy(buffer, ctime(&current), sizeof(buffer));

	if(current != -1)
	{
		// Convert time from seconds since Epoch to localtime.
		write(file_desc, buffer, sizeof(buffer));
	}

	// Close the file.
	close(file_desc);

	// Exit.
	exit(EXIT_SUCCESS);
}