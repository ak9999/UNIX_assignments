/*
 * Author: Abdullah Khan
 * Date: 2016-03-22
 * Program: jmp_test.c
 * Description: Shows setjmp and longjmp
 * Build instructions: make
 */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void first(char * string);
void second(char * string);

static jmp_buf env;

int main(void)
{
	char string[] = "in main()";
	printf("%s\n", string);

	if(!setjmp(env))
	{
		first(string);
	}
	else
	{
		printf("%s again!\n", string);
	}
	return 0;
}

void first(char * string)
{
	string = "in first(char*)\n";
	second(string);
	printf(string);
}

void second(char * string)
{
	string = "in second(char*)\n";
	printf(string);
	longjmp(env, 1);
}