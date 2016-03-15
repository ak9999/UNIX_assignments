/*
 * Author: Abdullah Khan
 * Date: 2016-03-01
 * Program: find_users.c
 * Description: Prints out usernames with UID and GID
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
#include <string.h>

// UNIX includes
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(void)
{
	struct passwd *pass;
	setpwent(); // Takes us to beginning of password database.
	while((pass = getpwent()) != NULL) // Iterate through /etc/passwd
	{
		printf("User: %20s\t UID: %6u\t\t GID: %6u\n",
			pass->pw_name,
			pass->pw_uid,
			pass->pw_gid);
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
