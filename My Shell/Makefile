#Source -> https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#C
CC=gcc
CFLAGS = -g -Wall -I.

# compiler flags:
# -I -> that gcc will look in the current directory
# -g -> adds debugging information to the executable file
# -Wall -> turns on most, but not all, compiler warnings

# the build target executable:
TARGET = my_shell

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
