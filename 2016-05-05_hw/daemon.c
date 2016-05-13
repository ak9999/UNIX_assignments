/*
 * daemon.c
 * This example daemonizes a process, writes a few log messages,
 * sleeps 20 seconds and terminates afterwards.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

void sighand(int sig)
{
    if(sig == SIGHUP)
    {

    }
    if(sig == SIGTERM)
    {
        syslog(LOG_NOTICE, "is now closing...\n");
        closelog();
        exit(0);
    }
}

static void d_init()
{
    time_t t;
    pid_t pid;

    /* Fork off the parent process */
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* On success: The child process becomes session leader */
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    /* Catch, ignore and handle signals */
    signal(SIGCHLD, sighand);
    signal(SIGHUP, sighand);

    /* Fork off for the second time*/
    pid = fork();

    /* An error occurred */
    if (pid < 0)
        exit(EXIT_FAILURE);

    /* Success: Let the parent terminate */
    if (pid > 0)
        exit(EXIT_SUCCESS);

    /* Set new file permissions */
    umask(0);

    // Change to home dir.
    chdir("~");

    /* Close all open file descriptors */
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>0; x--)
    {
        close(x);
    }

    /* Open the log file */
    openlog("Clockdaemon", LOG_PID, LOG_DAEMON);
}

int main()
{
    d_init();

    while (1)
    {
        syslog(LOG_NOTICE, "Clockdaemon started.");
        sleep (20);
        break;
    }

    return EXIT_SUCCESS;
}
