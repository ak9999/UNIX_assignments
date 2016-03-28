/*
Author: Abdullah Khan
Date: 2016-04-01
Program: shadow_cracker.c
Description: Dictionary-based password cracker.
Build instructions: make
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
#include <unistd.h> // for crypt
#include <shadow.h> // To read /etc/shadow

void crack_passphrase(char * enc_phrase, char * username, char * dict);

int main(int argc, char ** argv)
{
	if(argc != 2)
	{
		printf("Usage: %s <dictionary file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// If we don't have root permissions, notify the user and quit.
	if(geteuid() != 0) { printf("You need root privileges!\n"); exit(EXIT_SUCCESS); }

	char * dictionary = argv[1];

	struct spwd * shadow;
	setspent(); // Initialize position in /etc/shadow

	while((shadow = getspent()) != NULL) // Iterate through each entry
	{
		crack_passphrase(shadow->sp_pwdp, shadow->sp_namp, dictionary);
	}

	exit(EXIT_SUCCESS);
}

void crack_passphrase(char * enc_phrase, char * username, char * dict)
{
	FILE * dictionary = fopen(dict, "r");
	char buffer[256];
	//while(1)
	while((fscanf(dictionary, "%s", buffer) != EOF))
	{
		//if(!fgets(buffer, sizeof buffer, dictionary)) { break; }
		char salt[20];
		strncpy(salt, enc_phrase, 20);
		printf("%s\n", salt);
		char * potential_passphrase = crypt(buffer, salt);
		if(potential_passphrase == enc_phrase)
		{
			printf("User: %s\n Password: %s\n", username, buffer);
			break;
		}
	}
}
