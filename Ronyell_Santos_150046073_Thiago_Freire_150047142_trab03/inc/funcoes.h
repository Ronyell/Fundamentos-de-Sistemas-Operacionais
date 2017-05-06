#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 1000
#define NUM_THREADS 3

pthread_t threads[NUM_THREADS];
int x;

FILE * abrirArquivoSaida();

FILE * fecharArquivoSaida(FILE * output);

void escreverArquivoSaida(FILE * output, char * message);

void fecharArquivo(int * fd, int position);

void encerrarProcesso(int verificador);

void *funcao1(void *argumentos);

void *funcao2(void *argumentos);

void *funcao3(void *argumentos);

#endif
