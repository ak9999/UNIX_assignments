#include <unistd.h> /* for read(), write() */
#include <fcntl.h> /* for open() */
#include <string.h> /* for strlen() */
#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for calloc() */
#include <stdbool.h> /* for true */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>

#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int);
void PrintStatus(int status);
int main(int argc, char *argv[])
{
    if(argc != 2) { printf("Pass a file as a parameter.\n"); return -1; }
    
    struct rusage usage;

    int fd=open(argv[1],
                O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret, status;
    for (int n=0; n<3; n++)
    {
        if ((ret=fork())==0) /* child process */
        {
            Input(fd);
            printf("Child process, ret=%d.\n", ret);
            status=wait3(&status, WUNTRACED, &usage);
            switch(n)
            {
                case 0:
                    exit(7);
                    break;
                case 1:
                    abort();
                    break;
                case 2:
                    status=status/0;
                    break;
            }
        }
        else
        {
            printf("Parent process, child ret==%d.\n", ret);
            wait3(&status, WNOHANG, &usage);
            PrintStatus(status);
        }
    }
    printf("%ld.%06ld\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    return 0;
}

void Input(int filedes)
{
    char **name=calloc(3, 20*sizeof(char));
    char **it;
    name[0]="Abdullah Khan\n";
    name[1]="Not Abdullah\n";
    name[2]="Mega Man\n";
    for (it=&name[0]; *it!=NULL; it++)
    {
        ssize_t num_bytes=write(filedes, *it, strlen(*it));
        sleep(2);
    }
}
void PrintStatus(int status)
{
    int lower_8_bits;
    if ((lower_8_bits=WIFEXITED(status))==true)
    {
        printf("WIFEXITED(status)=%d\n",
               WIFEXITED(status));
        printf("Exit status for child=%d\n",
               WEXITSTATUS(status));
        printf("lower_8_bits=%x\n", status);
    }
    else if (WIFSIGNALED(status)==true)
    {
        printf("WIFSIGNALED(status)=%d\n",
               WIFSIGNALED(status));
        printf("Exit status for child=%d\n",
               WTERMSIG(status));
        printf("Exit status for child=%d\n",
               WCOREDUMP(status));
    }
    else if (WIFSTOPPED(status)==true)
    {
        printf("WIFSTOPPED(status)=%d\n",
               WIFSTOPPED(status));
        printf("Exit status for child=%d\n",
               WSTOPSIG(status));
    }
}
