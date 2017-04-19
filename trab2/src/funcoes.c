#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/time.h>
#include <sys/signal.h>

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

double calculaTempoTotalSegundos(double tempoInicialSegundos){
  struct timeval tempoFinal;
  gettimeofday(&tempoFinal, NULL);
  double tempoFinalSegundos = tempoFinal.tv_sec * 1.0 + tempoFinal.tv_usec / 1000000.0;
  double tempo = tempoFinalSegundos - tempoInicialSegundos;

  return tempo;
}

double calculaTempoInicialSegundos(){
  struct timeval tempoInicial;
  gettimeofday(&tempoInicial, NULL);
  double tempoInicialSegundos = tempoInicial.tv_sec * 1.0 + tempoInicial.tv_usec / 1000000.0;

  return tempoInicialSegundos;
}
