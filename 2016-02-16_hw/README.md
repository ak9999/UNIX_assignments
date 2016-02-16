# Assignment:

1. Write a small program illustrating the use of the `chown()` system call.
2. Write a program that displays all the information from the stat structure about
    a file in a “formatted” table, with the constant names on the left, and their binary
    values on the right. In particular, the st_mode member of the stat structure,
    which encodes the file type and the permissions mode, should be broken down into
    the values of its components, given that each bit has a meaning. List the meanings
    of each bit of st_mode and its values for your file. Convert into binary using the %
    operator on the octal value of st_mode , then test against the values obtained by
    selecting each bit using bitwise operations.

    There are 16 bits for st_mode (no two leading 0 bits as in the mask examples):
    • 1 for set-user-ID
    • 1 for set-group-ID
    • 1 for the sticky bit
    • 4 for the file type
    • 9 for access permissions
