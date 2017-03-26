#include <stdio.h>
#include <string.h>

/*
* Função que imprime o nome do executável
*/
void imprimeNome(char * nome);


int main (int argc, char* argv[]){
  imprimeNome(argv[0]);

  printf ("Quantidade de parametros %d\n", argc - 1);

  if (argc > 1) {
    int i;

    for (i = 1; i < argc; ++i)
      printf ("Parametro# %d: %s\n", i, argv[i]);
  }

  return 0;
}


void imprimeNome(char * nome){
  int contador = 0;

  printf ("Nome do executavel: ");
  while(nome[contador] != '\0'){

    if(contador > 1){
      printf("%c", nome[contador]);
    }
    contador ++;
  }

  printf("\n");
}
