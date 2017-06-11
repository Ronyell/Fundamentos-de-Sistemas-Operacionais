#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>



void listdir(const char *name, int level,const char *file_name)
{
    DIR *dir;
    struct dirent *entry;
    char * file = file_name;

    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
              continue;
            }
            listdir(path, level + 1, file_name);
        }
        else{
          //Verificando se possuem arquivos com o nome informado
          char *is_file_name = NULL;


          is_file_name = strstr(entry->d_name, file);
          if(is_file_name != NULL){
           printf("Arquivo encontrado: %s\n", entry->d_name);
         } else {
           //NOTHIN TO DO.
          }
        }

    } while (entry = readdir(dir));
    closedir(dir);
}


int main(int argc, char * argv[]){
  if (argc > 2)
    {
    DIR *directory;
    struct dirent *dir;
    int path_size = strlen(argv[1]);
    char path[path_size];
    memcpy(path, argv[1], path_size);

    int file_name_size = strlen(argv[2]);
    char file_name[file_name_size];
    memcpy(file_name, argv[2], file_name_size);

    listdir(path, 0, file_name);

  } else {
    printf("Quantidade de parâmetros inválida.\n");
  }

  return 0;
}
