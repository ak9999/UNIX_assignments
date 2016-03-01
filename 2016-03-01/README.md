# Assignment:
Write a cron job that appends the current date and time into a temporary file.
The output should be in a formatted table.

# Building:
Run `make`.

# Running:
Execute `maketemp`.
The temporary file is saved as `/tmp/tempFILE`.
This is the only way to make sure we have the same file every time the program runs.

# Cron job???
Run crontab -e to edit your crontab file and add the program to it.
