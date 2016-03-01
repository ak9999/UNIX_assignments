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
#include <dirent.h>
#include <limits.h>

// POSIX includes
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char ** argv)
{
	exit(EXIT_SUCCESS);
}