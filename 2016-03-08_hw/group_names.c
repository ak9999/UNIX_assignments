/*
 * Author: Abdullah Khan
 * Date: 2016-03-01
 * Program: group_names.c
 * Description: Prints out groups a user belongs to.
 * Build instructions: make
 */

/* If using a compiler that defaults to C99 or later */
#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 700
#else
#define _XOPEN_SOURCE 600
#endif /* __STDC_VERSION__ */

// STDC includes
#include <stdio.h>
#include <stdlib.h>

// UNIX includes
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h> // for NGROUPS_MAX
#include <grp.h>

int main(int argc, char ** argv)
{
	struct group *ptr;
	setgrent(); // Open the /etc/group at the beginning.
	gid_t grouplist[NGROUPS_MAX];
	int num_groups = getgroups(NGROUPS_MAX, grouplist);
	for(int i = 0; i < num_groups; i++)
	{
		gid_t curr_id = grouplist[i];
		if(getgrgid(curr_id))
		{
			printf("GID: %6u\t Group name: %20s\n",
				   	grouplist[i],
				   	ptr->gr_name);
		}
	}
	endgrent(); // Close /etc/groups
	exit(EXIT_SUCCESS);
}
