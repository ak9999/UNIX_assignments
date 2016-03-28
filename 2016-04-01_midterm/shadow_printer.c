/*
Author: Abdullah Khan
Date: 2016-04-01
Program: shadow_printer.c
Description: Print /etc/shadow
Build instructions: make printer
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
#include <sys/types.h>
#include <shadow.h> // To read /etc/shadow
#include <crypt.h> // To encrypt passphrases

void crack_passphrase(char * enc_phrase, char * username, FILE * dict);

int main(int argc, char ** argv)
{
	//if(argc != 2) { return -1; }
	
	if(geteuid() != 0) { printf("You need root privileges!\n"); exit(EXIT_SUCCESS); }
	struct spwd * shadow;
	setspent(); // Initialize position in /etc/shadow

	while((shadow = getspent()) != NULL) // Iterate through each entry
	{
		printf("%s: %s\n",
			shadow->sp_namp,
			shadow->sp_pwdp);
	}
	
	exit(EXIT_SUCCESS);
}