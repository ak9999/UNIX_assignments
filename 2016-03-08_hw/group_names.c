/*
Author: Abdullah Khan
Date: 2016-03-01
Program: group_names.c
Description: Prints out groups a user belongs to.
Build instructions: make
*/

/* If using a compiler that defaults to C99 or later */
#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 700
#else
#define _XOPEN_SOURCE 600
#endif /* __STDC_VERSION__ */

// C includes
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// UNIX includes
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h> // for NGROUPS_MAX
#include <pwd.h>
#include <grp.h>

int main(int argc, char * argv[])
{
	int numGroups;
	gid_t *grouplist;
	struct group *gr;

	grouplist = (gid_t*)malloc(sizeof(gid_t) * NGROUPS_MAX);

	// Get number of groups the user is in.
	if((numGroups = getgroups(0,NULL)) < 0)
	{
		printf("ERROR: getgroups() failure #1.");
		exit(1);
	}

	if((numGroups = getgroups(NGROUPS_MAX, grouplist)) < 0)
	{
		printf("ERROR: getgroups() failure #2.");
		exit(2);
	}

	if(numGroups >= 0)
	{
		// Print out GIDs and group names.
		printf("GIDs\t%20s\n", "Group names");
		for(unsigned int i = 0; i < numGroups; i++)
		{
			printf("%u\t", grouplist[i]);
			if((gr = getgrgid(grouplist[i])) != NULL)
			{
				printf("%20s\n", gr->gr_name);
			}
		}
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
