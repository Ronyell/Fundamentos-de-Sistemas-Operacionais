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

FILE * fecharArquivoSaida(FILE * output){
    fclose(output);
    return output;
}

void escreverArquivoSaida(FILE * output, char * message){
  fprintf(output, "%s\n", message );
}

int randomSleep(){
  int sleepTime = 0;
  struct timeval tempoFinal;

  gettimeofday(&tempoFinal, NULL);
  srand((int)tempoFinal.tv_usec);
  sleepTime=rand()%3;

  return sleepTime;
}

void fecharProcessos(pid_t filhoAtivo, pid_t filhoDorminhoco){
  int verificaAtivo = -1;
  int verificaDorminhoco =  -1;
  do{
    verificaAtivo =  kill(filhoAtivo, SIGKILL);
    verificaDorminhoco =  kill(filhoDorminhoco, SIGKILL);
    // Verificar se os processos filhos foram ecerrado.
    if(verificaAtivo != 0){
    printf("Houve um erro ao encerrar o proceso ativo\n");
    }
    if(verificaDorminhoco != 0){
    printf("Houve um erro ao encerrar o proceso dorminhoco\n");
    }
  } while(verificaDorminhoco != 0 || verificaAtivo != 0);
}
