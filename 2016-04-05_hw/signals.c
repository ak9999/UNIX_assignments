/*
 * Author: Abdullah Khan
 * Date: 2016-04-05
 * Program: signals.c
 * Description: Play with signals.
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
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void print_sig_set(const sigset_t *sigset)
{
    int count = 0;
    for(int sig = 1; sig < NSIG; sig++)
    {
        if(sigismember(sigset, sig))
        {
            count++;
            printf("%d %s\n", sig, strsignal(sig));
        }
    }
    if(count == 0) { puts("Empty signal set"); }
}

void catcher(int signo) {
    switch (signo) {
        case SIGUSR1: puts("catcher caught SIGUSR1");
        break;
        case SIGUSR2: puts("catcher caught SIGUSR2");
        break;
        case SIGINT: puts("catcher caught SIGINT (Ctrl-C)");
        break;
        default: printf("catcher caught unexpected signal %d\n", signo);
    }
}

int main(void)
{
    sigset_t sigset;
    struct sigaction sact;
    time_t t;

    sigset_t oldset, newset, waitset;
    sigemptyset(&oldset);
    sigemptyset(&newset);
    sigemptyset(&waitset);

    puts("Printing signal sets.");
    print_sig_set(&oldset);
    print_sig_set(&newset);
    print_sig_set(&waitset);

    if (fork() == 0)
    {
        sleep(5); // Wait 5 seconds.
        puts("child is sending SIGUSR2 signal - which should be blocked");
        kill(getppid(), SIGUSR2);
        sleep(5); // Wait 5 more.
        puts("child is sending SIGUSR1 signal - which should be caught");
        kill(getppid(), SIGUSR1);
        sleep(5);
        puts("child is sending SIGINT (Ctrl-C) - should be caught");
        kill(getppid(), SIGINT);
        exit(0);
    }

    sigemptyset(&sact.sa_mask);
    sact.sa_flags = 0;
    sact.sa_handler = catcher;
    if (sigaction(SIGUSR1, &sact, NULL) != 0)
    {
        puts("1st sigaction() error");
    }

    else if (sigaction(SIGUSR2, &sact, NULL) != 0)
    {
        puts("2nd sigaction() error");
    }

    else if (sigaction(SIGINT, &sact, NULL) != 0)
    {
        puts("3rd sigaction() error");
    }

    else
    {
        sigfillset(&sigset);
        sigdelset(&sigset, SIGUSR1);
        time(&t);
        printf("parent is waiting for child to send SIGUSR1 at %s", ctime(&t));
        if (sigsuspend(&sigset) == -1)
        {
            puts("sigsuspend() returned -1 as expected");
        }
        time(&t);
        printf("sigsuspend is over at %s", ctime(&t));
    }

    return 0;
}
