/*
 * Author: Abdullah Khan
 * Date: 2016-02-16
 * Program: chown_clone.c
 * Description: Illustrates use of `chown()`
 * Build instructions: make
 */

/*
 * <pwd.h> header provides a definition for struct passwd,
 * which includes members like uid_t pw_uid, numerical user ID
 * and gid_t pw_gid, numerical group ID.
*/
#include <pwd.h>
#include <fcntl.h> /* For creating, reading, and writing to files. */
#include <stdio.h> /* For standard input and output functions. */
#include <stdlib.h> /* For exit() */
#include <unistd.h> /* POSIX API */
#include <sys/stat.h> /* For mode_t */
#include <sys/types.h>

int main(int argc, char ** argv)
{
    if(argc != 3 || argv[1][0] == '\0')
    {
        printf("Usage: %s \"OWNER\" \"FILE\"\n", argv[0]);
        printf("\"OWNER\" can be specified as a numeric user ID or as a username.\n");
        exit(EXIT_FAILURE);
    }

    struct passwd *pwd;
    char * p_end; // needed for strtol()
    uid_t uid = strtol(argv[1], &p_end, 10); // Allow numeric strings of base 10.

    if(*p_end != '\0') // if username instead of numeric string
    {
        pwd = getpwnam(argv[1]); // try getting UID for username
        if(pwd == NULL) // We have a problem.
        {
            printf("Could not get UID for username.\n");
            exit(EXIT_FAILURE);
        }
        uid = pwd->pw_uid;
    }

    if(chown(argv[2], uid, -1) == -1)
    {
        printf("Could not change ownership of file.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
