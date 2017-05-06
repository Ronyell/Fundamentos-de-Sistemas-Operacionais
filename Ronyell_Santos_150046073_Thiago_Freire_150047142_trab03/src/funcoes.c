#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <string.h>
#include "funcoes.h"

void fecharArquivo(int * fd, int position){
  close(fd[position]);
}

void escreverArquivo(int * fd, char * message){
  write(fd[WRITE], message, strlen(message)+1);
}

int lerArquivo(int * fd, char * message){
  int size = read(fd[READ], message, BUFFER_SIZE);
  return size;
}

FILE * abrirArquivoSaida(){
    FILE *output;

    output = fopen("output.txt", "a+");

    if(output == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
    }

    return output;
}

void *funcao1(void *argumentos){
   printf("\nThread 1\n");
   return (NULL);
}

void *funcao2(void *argumentos){
   printf("\nThread 2\n");
   return (NULL);
}

void *funcao3(void *argumentos){
   printf("\nThread 3\n");
   return (NULL);
}

void encerrarProcesso(int verificador){
  switch (verificador) {
          case SIGINT:
               printf("Caught SIGINT, exiting now\n");
              //pthread_join(threadProdutora,NULL);
              //pthread_join(threadConsumidora1,NULL);
              //pthread_join(threadConsumidora2,NULL);
              exit(0);
              break;
          default:
          break;
  }

}
