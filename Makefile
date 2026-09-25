# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
TARGETS = task1 task2

# Default target compiles all programs
all: $(TARGETS)

# Compile task1 executable
task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

# Compile task2 executable
task2: task2.c
	$(CC) $(CFLAGS) -o task2 task2.c

# Clean up build artifacts and executables
clean:
	rm -f $(TARGETS) task1.exe task2.exe *.o

.PHONY: all clean
