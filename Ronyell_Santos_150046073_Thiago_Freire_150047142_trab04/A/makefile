INCFOLDER := inc/
SRCFOLDER := src/
OBJFOLDER := obj/

CC := gcc
CFLAGS := -Wall
CFLAGSSTATIC := ar -cr
MKDIR := mkdir -p

SRCFILEMAIN := $(wildcard src/main.c)
SRCFILESENO := $(wildcard src/libseno.c)

.PHONY : all clean

all: createFolders static program

program: $(SRCFILEMAIN:src/main.c=obj/main.o)
	$(CC) $(CFLAGS) obj/main.o -o main ./obj/libseno.a

obj/main.o: src/main.c
		$(CC) -c -static $< -o $@ -I./inc -I./inc

static: $(SRCFILESENO:src/libseno.c=obj/libseno.o)
		 $(CFLAGSSTATIC) obj/libseno.a obj/libseno.o

obj/libseno.o: src/libseno.c
	$(CC)  $(CFLAGS) -c $< -o $@ -I./inc

createFolders:
	$(MKDIR)  $(OBJFOLDER)

clean:
	rm -rf obj
	rm -rf main
