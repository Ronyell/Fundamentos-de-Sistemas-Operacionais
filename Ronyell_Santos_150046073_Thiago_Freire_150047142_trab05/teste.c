#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
int NUMBER_FILE = 0;
int found_files;

void print_content_file(char * file_path){
  found_files --;
  if(found_files >= 0){
      FILE *file;
      file=fopen(file_path,"r");
      int j;
      char charactere;
      NUMBER_FILE++;
      printf("%d.%s --\n", NUMBER_FILE, file_path);
      for(j = 0; j<30;j++){
          charactere= fgetc(file);
          if(charactere == EOF)
              break;
          printf("%c",charactere);
      }
      printf("\n");
      fclose(file);
  }
}


void listdir(const char *name, int level,const char *file_name, int number_file)
{
    DIR *dir;
    struct dirent *entry;
    char * file = file_name;
    char file_path[1024];

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
            listdir(path, level + 1, file_name, number_file);
        }
        else{
          char *is_file_name = NULL;
          //Verificando se possuem arquivos com o nome informado
          is_file_name = strstr(entry->d_name, file);

          if(is_file_name != NULL){
           //Concatenando a string do caminho com a / e com o nome do arquivo.
           strcpy(file_path, name);
           strcat(file_path, "/");
           strcat(file_path, entry->d_name);
           print_content_file(file_path);
            }
         }

    } while (entry = readdir(dir));
    closedir(dir);
}


int main(int argc, char **argv){
  if (argc > 3)
    {
    DIR *directory;
    struct dirent *dir;
    int path_size = strlen(argv[1]);
    char path[path_size];
    memcpy(path, argv[1], path_size);

    int file_name_size = strlen(argv[2]);
    char file_name[file_name_size];
    memcpy(file_name, argv[2], file_name_size);

    found_files = atoi(argv[3]);

    listdir(path, 0, file_name, found_files);

  } else {
    printf("Quantidade de parâmetros inválida.\n");
  }

  return 0;
}
