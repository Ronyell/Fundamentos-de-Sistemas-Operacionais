BINFOLDER := bin/
INCFOLDER := inc/
SRCFOLDER := src/
OBJFOLDER := obj/

CC := gcc
CFLAGS := -Wall
CFLAGSDYNAMIC := -fPIC -shared -g
MKDIR := mkdir -p

SRCFILES := $(wildcard src/*.c)

all: 	$(SRCFILES:src/*=obj/*)
	$(CC) $(CFLAGSDYNAMIC) src/libseno.c -o obj/libseno.so -I./inc
	$(CC) $(CFLAGS) obj/*.o -o bin/main ./obj/libseno.so

obj/main.o: src/main.c
		$(CC) $(CFLAGS) -c $< -o $@ ./obj/*.so

obj/libseno.so: src/libseno.c
	$(MKDIR)  $(OBJFOLDER)
	$(MKDIR) $(BINFOLDER)
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

dynamic: 	$(SRCFILES:src/libseno.c=obj/libseno.so)
		$(CC) $(CFLAGSDYNAMIC) src/libseno.c -o obj/libseno.so -I./inc


.PHONY: clean
clean:
	rm -rf obj
	rm -rf bin

run:
		bin/main
