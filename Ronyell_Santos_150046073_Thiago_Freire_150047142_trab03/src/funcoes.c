#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <string.h>
#include "funcoes.h"


FILE * criarArquivoLog(char * nomeArquivo){

    arquivoLog = fopen(nomeArquivo, "w+");

    if(arquivoLog == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        exit(-1);
    }
    return arquivoLog;
}

void fecharArquivoLog(){
  fclose(arquivoLog);
}

void *funcaoProdutora(void *argumentos){
    int aguardar = FALSE;
    int numero = numeroRandomico();
    maiorOcupacao = 0;

    while(!solicitacaoTermino){

        do{
            pthread_mutex_lock(&mutex);
            aguardar = FALSE;
            if (quantidadeAtual == BUFFER_SIZE){
                aguardar = TRUE;
                pthread_mutex_unlock(&mutex);
            }

            if(solicitacaoTermino){
                break;
            }
        } while (aguardar == TRUE);

        if(solicitacaoTermino){
            break;
        }

        fprintf(arquivoLog, "[producao]: Numero gerado %d\n", numero);
        insereNo(BUFFER, &quantidadeAtual, numero);

        if(maiorOcupacao < quantidadeAtual){
            maiorOcupacao = quantidadeAtual;
        }
	    pthread_mutex_unlock(&mutex);

        usleep(100000);
        numero = numeroRandomico();

    }
    return (NULL);
}

void *funcaoConsumidora(void *argumentos){
    int aguardar = FALSE;
    char caracter = *(char*)argumentos;
    Node * no = (Node *) malloc(sizeof(Node));

    while(!solicitacaoTermino){

        do{
            pthread_mutex_lock(&mutex);
            aguardar = FALSE;
            if (quantidadeAtual == 0){
                aguardar = TRUE;
                pthread_mutex_unlock(&mutex);
            }

            if(solicitacaoTermino){
                break;
            }

        } while (aguardar == TRUE);

        if(solicitacaoTermino){
            break;
        }

        no = retiraNo(BUFFER, &quantidadeAtual);
        fprintf(arquivoLog, "[consumo %c]: Numero lido %d\n", caracter, no->numero );
        if(primeiroConsumido){
          maiorNumero = no->numero;
          menorNumero = no->numero;
          primeiroConsumido = FALSE;
        }
        if(no->numero > maiorNumero){
            maiorNumero = no->numero;
        }
        if(no->numero < menorNumero){
            menorNumero = no->numero;
        }

        pthread_mutex_unlock(&mutex);

        //TODO arrumar o tempo
        usleep(150000);

    }
    return (NULL);
}

void encerrarProcesso(int verificador){
    switch (verificador) {
        case SIGINT:
        fprintf(arquivoLog, "\n[aviso]: Termino solicitado. Aguardando threads...\n");
        printf("\n[aviso]: Termino solicitado. Aguardando threads...\n");
            solicitacaoTermino = 1;
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
