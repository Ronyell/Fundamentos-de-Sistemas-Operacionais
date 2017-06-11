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

void print_all_files(struct dirent *dir, DIR *directory, char * argv){
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
        printf("Arquivo encontrado: %s\n", dir);
      }
    }
  }
}

int main(int argc, char * argv[]){

  DIR *directory;
  struct dirent *dir;
  int size = strlen(argv[1]);
  char path[size];

  memcpy(path, argv[1], size);

  directory = opendir(path);

  if(directory == NULL){
    printf("Não foi possível achar o diretório");
  }
  //Abrindo o diretorio local e imprimindo só os nomes de arquivos
  else
  {
    print_all_files(dir, directory, argv[1]);
    closedir(directory);
  }

  return 0;
}
