SRCFOLDER := src/

CC := gcc
CFLAGS := -W -Wall -Wshadow -pedantic

SRCFILES := $(wildcard src/*.c)

all: $(SRCFILES:src/%.c=%.o)
	$(CC) $(CFLAGS) *.o -o main
	rm -rf *.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf main
