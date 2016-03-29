# Dictionary-based attack on /etc/shadow

# Building
Run `make`

# Usage

The `cracker` program can be run two ways:
1. `cracker <dictionary file>
    The program will run the attack against /etc/shadow.
    You will need root privileges to read /etc/shadow.
2. `cracker <path/to/shadow/file> <dictionary file>`
    You can also run the program against a shadow file of your choosing,
    (in case you've already got one you can read without needing root)

# How it works
The attack will read the first entry in the shadow file, then start
encrypting each word in the dictionary file using crypt, using the first
20 characters of the shadow password as a salt.

After a match is found, the user and cleartext password are printed, and
we move on to the next entry. If we exhaust the dictionary, we move on as
well.

