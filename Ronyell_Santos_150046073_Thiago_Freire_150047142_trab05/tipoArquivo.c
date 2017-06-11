#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    int is_file = 0;
    is_file = S_ISREG(path_stat.st_mode);
    return is_file;
}

void print_all_files(struct dirent *dir, DIR *directory, char * argv, char * file_name){
  char * file = file_name;
  int exist_file = 0;

  while ((dir = readdir(directory)) != NULL)
  {
    if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0){
      //Não lista os arquivos . e ..
    }
    else{
      int is_file = 0;
      int size = strlen(argv);
      char path[size];

      memcpy(path, argv, size);

      fflush(stdin);
      strcat(path, dir->d_name);
      is_file = is_regular_file(path);

      if(is_file){
        //Verificando se possuem arquivos com o nome informado
        char *is_file_name = NULL;


        is_file_name = strstr(dir->d_name, file);
        if(is_file_name != NULL){
         printf("Arquivo encontrado: %s\n", dir->d_name);
         exist_file = 1;
       } else {
         //NOTHIN TO DO.
        }
      }
    }
  }
  if(!exist_file){
     printf("Não há arquivos com esse nome.\n");
   }
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

    directory = opendir(path);

    if(directory == NULL){
      printf("Não foi possível achar o diretório");
    }
    //Abrindo o diretorio local e imprimindo só os nomes de arquivos
    else
    {
      print_all_files(dir, directory, path, file_name);
      closedir(directory);
    }
  } else {
    printf("Quantidade de parâmetros inválida.\n");
  }

  return 0;
}
