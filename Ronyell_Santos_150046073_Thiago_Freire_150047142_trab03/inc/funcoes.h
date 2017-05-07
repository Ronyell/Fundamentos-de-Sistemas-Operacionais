#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "fila.h"

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 5
#define NUM_THREADS 3
#define TRUE 1
#define FALSE 0

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
Node * BUFFER;
int quantidadeAtual;
int maiorOcupacao;
int maiorNumero;
int menorNumero;
int solicitacaoTermino;


FILE * abrirArquivoSaida();

FILE * fecharArquivoSaida(FILE * output);

void escreverArquivoSaida(FILE * output, char * message);

void fecharArquivo(int * fd, int position);

void encerrarProcesso(int verificador);

void *funcaoProdutora(void *argumentos);

void *funcaoConsumidora(void *argumentos);

int numeroRandomico();

#endif
