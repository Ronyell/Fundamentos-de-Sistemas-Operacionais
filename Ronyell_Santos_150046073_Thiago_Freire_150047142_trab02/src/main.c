#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include <stdio_ext.h>
#include <sys/signal.h>
#include "funcoes.h"

int main(){
  // Variaveis relacionadas ao filho ativo
  pid_t filhoAtivo;

  // Variaveis relacionadas ao filho dorminhoco
  pid_t filhoDorminhoco;

  // Criação do pipe para o filho Ativo
  // int statusAtivo;

  struct timeval tempoInicial;
  gettimeofday(&tempoInicial, NULL);
  double tempoInicialSegundos = tempoInicial.tv_sec * 1.0 + tempoInicial.tv_usec / 1000000.0;


  int fdAtivo[2];

  if (pipe(fdAtivo) == -1){
    return 1;
  }

  // Criação do pipe para o filho Dorminhoco
  // int statusDorminhoco;

  filhoAtivo = fork();

  if(filhoAtivo > 0){ // Funções do processo Pai
    // fecharArquivo(fdAtivo, WRITE);
    close(fdAtivo[WRITE]);

    int fdDorminhoco[2];

    if (pipe(fdDorminhoco) == -1){
      return 1;
    }

    filhoDorminhoco = fork();

    if(filhoDorminhoco > 0){ // Funções do processo Pai Dorminhoco
      // fecharArquivo(fdDorminhoco, WRITE);
      close(fdDorminhoco[WRITE]);

    }else{// Funções do processo Dorminhoco
      // fecharArquivo(fdDorminhoco, READ);
      close(fdDorminhoco[READ]);
      fd_set rfdDorminhoco;
      FD_ZERO(&rfdDorminhoco);

      int i = 0;
      for (i = 0; ; i++){
        FD_SET(fdDorminhoco[WRITE], &rfdDorminhoco);

        int retvalDorminhoco = select(fdDorminhoco[WRITE] + 1, NULL, &rfdDorminhoco, NULL, NULL);

        if(retvalDorminhoco > 0){
          char message[BUFFER_SIZE];
          struct timeval tempoFinal;
          gettimeofday(&tempoFinal, NULL);
          double tempoFinalSegundos = tempoFinal.tv_sec * 1.0 + tempoFinal.tv_usec / 1000000.0;
          double tempo = tempoFinalSegundos - tempoInicialSegundos;

          //printf("Tempo Inicial: %ld %ld\n", tempoInicial.tv_sec, tempoInicial.tv_usec);
          sprintf(message, "0:%06.3lf: %s %02d %s", tempo, "Mensagem", i+1," do filho dorminhoco.");
          escreverArquivo(fdDorminhoco, message);
          int random = randomSleep();
          sleep(random);
        }else{
          i--;
        }
      }
      // fecharArquivo(fdDorminhoco, WRITE);
      close(fdDorminhoco[WRITE]);
    }
    //******************************************************************************************************
    // PAI DOS DOIS
    //******************************************************************************************************

    fd_set rfds;
    double tempo = 0;
    FD_ZERO(&rfds);

    while(tempo < 30){
      FD_SET(fdDorminhoco[READ], &rfds);
      FD_SET(fdAtivo[READ], &rfds);

      struct timeval tempoFinal;
      gettimeofday(&tempoFinal, NULL);
      double tempoFinalSegundos = tempoFinal.tv_sec * 1.0 + tempoFinal.tv_usec / 1000000.0;
      tempo = tempoFinalSegundos - tempoInicialSegundos;
      int retval = select(fdDorminhoco[READ] + 1, &rfds, NULL, NULL, NULL);
      if(retval > 0){

        gettimeofday(&tempoFinal, NULL);
        tempoFinalSegundos = tempoFinal.tv_sec * 1.0 + tempoFinal.tv_usec / 1000000.0;
        tempo = tempoFinalSegundos - tempoInicialSegundos;
        if (FD_ISSET(fdAtivo[READ], &rfds)>0){
          char message1[BUFFER_SIZE]="";
          char message[BUFFER_SIZE]="";
          int size = lerArquivo(fdAtivo,message1);
          if (size){
            FILE * output = abrirArquivoSaida();
            sprintf(message, "0:%06.3lf: %s", tempo, message1);
            escreverArquivoSaida(output,message);
            output = fecharArquivoSaida(output);
          }
        }

        gettimeofday(&tempoFinal, NULL);
        tempoFinalSegundos = tempoFinal.tv_sec * 1.0 + tempoFinal.tv_usec / 1000000.0;
        tempo = tempoFinalSegundos - tempoInicialSegundos;

        if (FD_ISSET(fdDorminhoco[READ], &rfds)>0){
          char message2[BUFFER_SIZE]="";
          char message[BUFFER_SIZE]="";
          int size = lerArquivo(fdDorminhoco,message2);
          if (size){
            FILE * output = abrirArquivoSaida();
            sprintf(message, "0:%06.3lf: %s", tempo, message2);
            escreverArquivoSaida(output,message);
            output = fecharArquivoSaida(output);
          }
        }
      }
    }

    fecharProcessos(filhoDorminhoco, filhoAtivo);

//******************************************************************************************************

  }else{// Funções do processo Ativo
    close(fdAtivo[READ]);
    fd_set rfdAtivo;
    FD_ZERO(&rfdAtivo);

    int i = 1;
    for (i = 1;; i++){
      FD_SET(fdAtivo[WRITE], &rfdAtivo);


      char message[BUFFER_SIZE];
      char entrada[BUFFER_SIZE];

      fflush(stdin);
      __fpurge(stdin);

      scanf("%[^\n]",entrada);

      while((select(fdAtivo[WRITE] + 1, NULL, &rfdAtivo, NULL, NULL))<=0);

      struct timeval tempoFinal;
      gettimeofday(&tempoFinal, NULL);
      double tempoFinalSegundos = tempoFinal.tv_sec * 1.0 + tempoFinal.tv_usec / 1000000.0;
      double tempo = tempoFinalSegundos - tempoInicialSegundos;
      sprintf(message, "0:%06.3lf: %s %02d %s <%s>", tempo, "Mensagem", i," do usuário:", entrada);
      escreverArquivo(fdAtivo, message);
    }
    close(fdAtivo[WRITE]);
  }



  return 0;
}
