#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int NUMBER_FILE;
int found_files;

void print_content_file(char * file_path);

void listdir(const char *name, int level,const char *file_name, int number_file);

#endif
