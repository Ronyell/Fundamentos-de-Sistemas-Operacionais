#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdlib.h>
#include <stdio.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 5000

FILE * abrirArquivoSaida();

FILE * fecharArquivoSaida(FILE * output);

void escreverArquivoSaida(FILE * output, char * message);

void escreverArquivo(int * fd, char * message);

int lerArquivo(int * fd, char * message);

double calculaTempoInicialSegundos();

double calculaTempoTotalSegundos(double tempoInicialSegundos);

#endif
