#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

FILE * fecharArquivoSaida(FILE * output){
    fclose(output);
    return output;
}

void escreverArquivoSaida(FILE * output, char * message){
  fprintf(output, "%s\n", message );
}