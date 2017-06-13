#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "function.h"

int main(int argc, char **argv){
        if (argc > 3) {
                DIR *directory;
                struct dirent *dir;
                int path_size = strlen(argv[1]);
                char path[path_size];
                memcpy(path, argv[1], path_size);

                int file_name_size = strlen(argv[2]);
                char file_name[file_name_size];
                memcpy(file_name, argv[2], file_name_size);

                found_files = atoi(argv[3]);
                printf("Resultado de buscador \"%s\" na pasta %s\n", file_name, path);
                listdir(path, 0, file_name, found_files);

        } else {
                printf("Quantidade de parâmetros inválida.\n");
        }

        return 0;
}
