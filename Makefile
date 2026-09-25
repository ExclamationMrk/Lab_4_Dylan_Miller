# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
TARGETS = football_scorer temperature_converter

# Default target compiles all programs
all: $(TARGETS)

# Compile football_scorer executable
football_scorer: football_scorer.c
	$(CC) $(CFLAGS) -o football_scorer football_scorer.c

# Compile temperature_converter executable
temperature_converter: temperature_converter.c
	$(CC) $(CFLAGS) -o temperature_converter temperature_converter.c

# Clean up build artifacts and executables
clean:
	rm -f $(TARGETS) football_scorer.exe temperature_converter.exe *.o

.PHONY: all clean
