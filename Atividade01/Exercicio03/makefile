INCFOLDER := inc/
SRCFOLDER := src/

CC := gcc
CFLAGS := -W -Wall -Wshadow -pedantic

SRCFILES := $(wildcard src/*.c)

all: $(SRCFILES:src/%.c=%.o)
	$(CC) $(CFLAGS) *.o -o main
	rm -rf *.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

.PHONY: clean

clean:
	rm -rf main
