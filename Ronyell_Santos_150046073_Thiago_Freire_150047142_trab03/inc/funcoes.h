#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 1000

pthread_t threadProdutora;
pthread_t threadConsumidora1;
pthread_t threadConsumidora2;

FILE * abrirArquivoSaida();

FILE * fecharArquivoSaida(FILE * output);

void escreverArquivoSaida(FILE * output, char * message);

void fecharArquivo(int * fd, int position);

void encerrarProcesso(int verificador);

void *funcao1(void *argumentos);

void *funcao2(void *argumentos);

void *funcao3(void *argumentos);

#endif
