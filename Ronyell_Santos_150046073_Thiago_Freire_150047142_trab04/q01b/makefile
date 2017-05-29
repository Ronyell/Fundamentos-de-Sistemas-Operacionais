INCFOLDER := inc/
SRCFOLDER := src/
OBJFOLDER := obj/

CC := gcc
CFLAGS := -Wall
CFLAGSDYNAMIC := -fPIC -shared -g
MKDIR := mkdir -p

SRCFILEMAIN := $(wildcard src/main.c)
SRCFILESENO := $(wildcard src/libseno.c)

.PHONY : all clean

all:	createFolders dynamic program

program: $(SRCFILEMAIN:src/main.c=obj/main.o)
	$(CC) $(CFLAGS) obj/main.o -o trabalho_04 ./obj/libseno.so

obj/main.o: src/main.c
		$(CC) $(CFLAGS) -c $< -o $@ -I./inc

dynamic: $(SRCFILESENO:src/libseno.c=obj/libseno.so)
		$(CC) $(CFLAGSDYNAMIC) src/libseno.c -o obj/libseno.so -I./inc

obj/libseno.so: src/libseno.c
	$(CC) $(CFLAGSDYNAMIC) -c $< -o $@ -I./inc

createFolders:
	$(MKDIR)  $(OBJFOLDER)

clean:
	rm -rf obj
	rm -rf trabalho_04
