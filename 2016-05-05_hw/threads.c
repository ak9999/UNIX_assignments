/*
 * Author: Abdullah Khan
 * Date: 2016-05-05
 * Program: threads.c
 * Description: Play with threads.
 * Build instructions: make
 */

/* If using a compiler that defaults to C99 or later */
#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 700
#else
#define _XOPEN_SOURCE 600
#endif /* __STDC_VERSION__ */

#define _POSIX_SOURCE 1
#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <stdbool.h>

void get_eof(int sig)
{
    (void)sig;
    puts("(VINTR)");
    exit(EXIT_SUCCESS);
}

int main(void)
{
    int output = -1;
    if((output = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR)) == -1)
    {
        return -1;
    }

    bool run = true;
    setvbuf(stdout, NULL, _IONBF, 0);
    struct termios old_term, new_term;
    tcgetattr(0, &old_term);

    signal(SIGINT, get_eof);

    new_term = old_term;
    new_term.c_cc[VEOF] = 3; // ^C
    new_term.c_cc[VINTR] = 4; // ^D
    tcsetattr(0, TCSANOW, &new_term);
    while(run)
    {
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        while((read = getline(&line, &len, stdin)) != -1)
        {
            write(output, line, read);
        }
    }
    tcsetattr(0, TCSANOW, &old_term);
    return 0;
}
