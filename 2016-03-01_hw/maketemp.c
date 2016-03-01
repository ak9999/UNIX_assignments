/*
 * Author: Abdullah Khan
 * Date: 2016-03-01
 * Program: maketemp.c
 * Description: Creates a temporary file called /tmp/tempFILE and creates a table
 * with the time of execution in it.
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

int main(int argc, char ** argv)
{
	char tmp_template[] = "/tmp/tempFILE";

	char header[] = "Day Mon  # Time     Year\n";
	char dashes[] = "--- ---  - -------- ----\n";

	// Our current date and time since the Epoch
	char buffer[100];
	time_t current = time(NULL);

	FILE * pf;
	pf = fopen(tmp_template, "a+");
	printf("Temporary file %s created or accessed", tmp_template);
	printf("\n");

	// Check if file is open.
    if(pf != NULL)
    {
		// Convert time from seconds since Epoch to localtime.
		strncpy(buffer, ctime(&current), sizeof(buffer));
    	
    	// Check if the file already has the header.
    	char line[100];
    	fgets(line, sizeof(line), pf);
    	if(strcmp(header,line) != 0)
    	{
    		// If not, we add the header, the dashes, and timestamp.
    		fputs(header, pf);
    		fputs(dashes, pf);

    		if(current != -1)
			{
				fputs(buffer, pf);
			}

			// Unless we can't for some reason...
			else
			{
				printf("Failed to get time.\n");
				exit(EXIT_FAILURE);
			}
    	}

    	else
    	{
    		// If we have a header just append the timestamp.
	    	if(current != -1)
			{
				fputs(buffer, pf);
			}

			else
			{
				printf("Failed to get time.\n");
				exit(EXIT_FAILURE);
			}
    	}
    }

    else
    {
    	printf("Failed to open file.");
    	exit(EXIT_FAILURE);
    }

	// Close the file.
	fclose(pf);

	// Exit.
	exit(EXIT_SUCCESS);
}