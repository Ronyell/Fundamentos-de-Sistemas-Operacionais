#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <string.h>
#include "funcoes.h"


void criarArquivoLog(){

    arquivoLog = fopen("log.txt", "w+");

    if(arquivoLog == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
}

void fecharArquivoLog(char* nomeArquivo){
  rename("log.txt", nomeArquivo);
  fclose(arquivoLog);
}

void *funcaoProdutora(void *argumentos){
    int aguardar = FALSE;
    int numero = numeroRandomico();
    maiorNumero = numero;
    menorNumero = numero;
    maiorOcupacao = 0;

    while(!solicitacaoTermino){

        do{
            pthread_mutex_lock(&mutex);
            aguardar = FALSE;
            if (quantidadeAtual == BUFFER_SIZE){
                aguardar = TRUE;
                pthread_mutex_unlock(&mutex);
            }

            // TODO MELHORAR
            if(solicitacaoTermino){
                break;
            }
        } while (aguardar == TRUE);

        // TODO MELHORAR
        if(solicitacaoTermino){
            break;
        }

        fprintf(arquivoLog, "[producao]: Numero gerado %d\n", numero);
        insereNo(BUFFER, &quantidadeAtual, numero);

        if(numero > maiorNumero){
            maiorNumero = numero;
        }
        if(numero < menorNumero){
            menorNumero = numero;
        }
        if(maiorOcupacao < quantidadeAtual){
            maiorOcupacao = quantidadeAtual;
        }

	    pthread_mutex_unlock(&mutex);

        usleep(1000000);
        numero = numeroRandomico();

    }

    return (NULL);
}


void *funcaoConsumidora(void *argumentos){
    int aguardar = FALSE;
    char caracter = *(char*)argumentos;
    Node * no = (Node *) malloc(sizeof(Node));

    while(!solicitacaoTermino || quantidadeAtual){

        do{
            pthread_mutex_lock(&mutex);
            aguardar = FALSE;
            if (quantidadeAtual == 0){
                aguardar = TRUE;
                pthread_mutex_unlock(&mutex);
            }
        } while (aguardar == TRUE);

        no = retiraNo(BUFFER, &quantidadeAtual);
        fprintf(arquivoLog, "[consumo %c]: Numero lido %d\n", caracter, no->numero );
        pthread_mutex_unlock(&mutex);

        //TODO arrumar o tempo
        usleep(4000000);

    }

    return (NULL);
}

void encerrarProcesso(int verificador){
    switch (verificador) {
        case SIGINT:
        printf("\n[aviso]: Termino solicitado. Aguardando threads...\n");
            solicitacaoTermino = 1;
            int i = 0;

            // TODO MELHORAR
            for(i = 0; i< NUM_THREADS; i++){
                pthread_join(threads[i], NULL);
            }
        break;
    }
}

int numeroRandomico(){
  int numero = 0;
  int sinal = 0;
  struct timeval tempo;

  gettimeofday(&tempo, NULL);
  srand((int)tempo.tv_usec);

  sinal=rand()%2;
  numero = rand();

  if(!sinal){
      numero *= -1;
  }

  return numero;
}

void imprimirResultados(){
  printf("[aviso]: Maior numero gerado: %d\n", maiorNumero);
  printf("[aviso]: Menor numero gerado: %d\n", menorNumero);
  printf("[aviso]: Maior ocupacao de buffer: %d\n", maiorOcupacao);
  fprintf(arquivoLog, "[aviso]: Maior numero gerado: %d\n", maiorNumero);
  fprintf(arquivoLog, "[aviso]: Menor numero gerado: %d\n", menorNumero);
  fprintf(arquivoLog, "[aviso]: Maior ocupacao de buffer: %d\n", maiorOcupacao);
  printf("[aviso]: Aplicacao encerrada.\n");
}
