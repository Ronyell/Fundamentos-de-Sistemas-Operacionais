#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "fila.h"

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 50
#define TAMANHO_NOME_ARQUIVO 100
#define NUM_THREADS 3
#define TRUE 1
#define FALSE 0

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
Node * BUFFER;
char nomeArquivo[TAMANHO_NOME_ARQUIVO];
int quantidadeAtual;
int maiorOcupacao;
int maiorNumero;
int menorNumero;
int solicitacaoTermino;
FILE * arquivoLog;

void criarArquivoLog();

void fecharArquivoLog();

FILE * fecharArquivoSaida(FILE * output);

void escreverArquivoSaida(FILE * output, char * message);

void fecharArquivo(int * fd, int position);

void encerrarProcesso(int verificador);

void *funcaoProdutora(void *argumentos);

void *funcaoConsumidora(void *argumentos);

int numeroRandomico();

void imprimirResultados();

#endif
