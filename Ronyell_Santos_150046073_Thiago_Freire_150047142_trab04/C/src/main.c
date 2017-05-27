#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<dlfcn.h>


int main(int argc, char * argv[]){
  void *handle;
  double (*seno)(double);
  double  valor;
  char *error;

  handle = dlopen("./obj/libseno.so",RTLD_LAZY);
  if(!handle){
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }

  seno  = dlsym(handle, "seno");
  if((error = dlerror()) != NULL)
  {
    fprintf(stderr,"%s\n", error);
    exit(1);
  }

  printf("O Seno de %lf é %lf\n",10.0,(*seno)(100));

  dlclose(handle);
  return 0;
}
