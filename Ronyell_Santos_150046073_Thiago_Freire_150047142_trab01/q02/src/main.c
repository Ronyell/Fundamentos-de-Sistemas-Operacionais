#include <stdio.h>
#include <string.h>

  int main (int argc, char* argv[]){
    printf ("Nome do executavel: %s\n", argv[0]);
    printf ("Quantidade de parametros %d\n", argc - 1);

    if (argc > 1) {
      int i;
      for (i = 1; i < argc; ++i)
        printf ("Parametro# %d: %s\n", i, argv[i]);
    }

  return 0;
  }
