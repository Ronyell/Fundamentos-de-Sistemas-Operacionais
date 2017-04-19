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

  // Inicialização do tempo
  double tempoInicialSegundos = calculaTempoInicialSegundos();

  // Criação do pipe para o filho Ativo

  int fdAtivo[2];

  if (pipe(fdAtivo) == -1){
    return 1;
  }

  // Criação do pipe para o filho Dorminhoco

  filhoAtivo = fork();

  if(filhoAtivo > 0){ // Funções do processo Pai
    close(fdAtivo[WRITE]);

    int fdDorminhoco[2];

    if (pipe(fdDorminhoco) == -1){
      return 1;
    }

    filhoDorminhoco = fork();

    if(filhoDorminhoco > 0){ // Funções do processo Pai Dorminhoco
      close(fdDorminhoco[WRITE]);

    }else{// Funções do processo Dorminhoco
      close(fdDorminhoco[READ]);
      fd_set rfdDorminhoco;
      FD_ZERO(&rfdDorminhoco);

      for (int i = 0; ; i++){
        FD_SET(fdDorminhoco[WRITE], &rfdDorminhoco);

        int retvalDorminhoco = select(fdDorminhoco[WRITE] + 1, NULL, &rfdDorminhoco, NULL, NULL);

        if(retvalDorminhoco > 0){
          char message[BUFFER_SIZE];
          double tempo = calculaTempoTotalSegundos(tempoInicialSegundos);

          sprintf(message, "0:%06.3lf: %s %02d %s", tempo, "Mensagem", i+1," do filho dorminhoco.");
          escreverArquivo(fdDorminhoco, message);
          sleep(rand() % 3);
        }else{
          i--;
        }
      }
      close(fdDorminhoco[WRITE]);
    }
    //******************************************************************************************************
    // Código do Pai
    //******************************************************************************************************

    char messageBuffer[BUFFER_SIZE]="";
    char message[BUFFER_SIZE]="";
    fd_set rfds;
    double tempo = 0;
    FD_ZERO(&rfds);

    while(tempo < 30){
      FD_SET(fdDorminhoco[READ], &rfds);
      FD_SET(fdAtivo[READ], &rfds);

      int retval = select(fdDorminhoco[READ] + 1, &rfds, NULL, NULL, NULL);
      if(retval > 0){


        // Leitura do arquivo do processo Ativo
        if (FD_ISSET(fdAtivo[READ], &rfds)>0){
          int size = lerArquivo(fdAtivo,messageBuffer);
          if (size){
            FILE * output = abrirArquivoSaida();
            tempo = calculaTempoTotalSegundos(tempoInicialSegundos);
            sprintf(message, "0:%06.3lf: %s", tempo, messageBuffer);
            escreverArquivoSaida(output,message);
            output = fecharArquivoSaida(output);
          }
        }

        // Leitura do arquivo do processo Dorminhoco
        if (FD_ISSET(fdDorminhoco[READ], &rfds)>0){
          int size = lerArquivo(fdDorminhoco,messageBuffer);
          if (size){
            FILE * output = abrirArquivoSaida();
            tempo = calculaTempoTotalSegundos(tempoInicialSegundos);
            sprintf(message, "0:%06.3lf: %s", tempo, messageBuffer);
            escreverArquivoSaida(output,message);
            output = fecharArquivoSaida(output);
          }
        }
      }
    }

    // Encerramento dos processos filhos após 30 segundos de execução
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

    //******************************************************************************************************
    //
    //******************************************************************************************************

  }else{// Funções do processo Ativo
    close(fdAtivo[READ]);
    fd_set rfdAtivo;
    FD_ZERO(&rfdAtivo);

    for (int i = 1;; i++){
      FD_SET(fdAtivo[WRITE], &rfdAtivo);


      char message[BUFFER_SIZE];
      char entrada[BUFFER_SIZE];

      __fpurge(stdin);

      scanf("%[^\n]",entrada);

      while((select(fdAtivo[WRITE] + 1, NULL, &rfdAtivo, NULL, NULL))<=0);

      double tempo = calculaTempoTotalSegundos(tempoInicialSegundos);
      sprintf(message, "0:%06.3lf: %s %02d %s <%s>", tempo, "Mensagem", i," do usuário:", entrada);
      escreverArquivo(fdAtivo, message);
    }
    close(fdAtivo[WRITE]);
  }

  return 0;
}
