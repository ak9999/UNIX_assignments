/*
Modified by: Abdullah Khan
*/

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFSIZE 4096
#define FILESIZE 1474560

void Input(int);
void PrintStatus(int status);

int main(int argc, char ** argv)
{
	int fd = open(argv[1], O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	int ret, status;
	for(int i = 0; i < 3; i++)
	{
		if((ret = fork()) == 0)
		{
			Input(fd);
			printf("Child process, ret=%d.\n", ret);
			status = wait(&status);
			switch(n)
			{
				case 0:
					exit(7);
					break;
                case 1:
                    abort();
                    break;
                case 2:
                    status = status/0;
                    break;
			}
		}
        else
        {
            printf("Parent process, child ret==%d.\n", ret);
            wait(&status);
            PrintStatus(status);
        }
    }
    return 0;
}

void Input(int filedes)
{
    char **name = calloc(3, 20*sizeof(char));
    char **it;
    name[0] = "Abdullah Khan\n";
    name[1] = "Not Me\n";
    name[2] = "What Man\n";
    for(it = &name[0]; *it != NULL; it++)
    {
        ssize_t num_bytes = write(filesdes, *it, strlen(*it));
        sleep(2);
    }
}

void PrintStatus(int status)
{
    int lower_8_bits;
    if((lower_8_bits = WIFEXITED(status)) == true)
    {
        printf("WIFEXITED(status)=%d\n", WIFEXITED(status));
        printf("Exit status for child=%d\n", WEXITSTATUS(status));
        printf("lower_8_bits=%x\n", status);
    }
    else if (WIFSIGNALED(status) == true)
    {
        printf("WIFSIGNALED(status)=%d\n", WIFSIGNALED(status));
        printf("Exit status for child=%d\n", WTERMSIG(status));
        printf("Exit status for child=%d\n", WCOREDUMP(status));
    }
    else if(WIFSTOPPED(status) == true)
    {
        printf("WIFSTOPPED(status)=%d\n", WIFSTOPPED(status));
        printf("Exit status for child=%d\n", WSTOPSIG(status));
    }
}

