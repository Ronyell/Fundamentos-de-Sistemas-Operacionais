#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <stdio.h>
#include <stdlib.h>

#define CREASING "-d"
#define DECREASING "-r"

/*
* Função que aloca espaço para o vetor
*/
int * arrayAllocation();

/*
* Função que realoca espaço para o vetor
*/
int * arrayReallocation(int lengh, int *arrayOfNumbers);

/*
* Função que organiza o vetor de forma crescente
*/

void arrayCreasing(int lengh, int * arrayOfNumbers);

/*
* Função que organiza o vetor de forma decrescente
*/

void arrayDecreasing(int lengh, int * arrayOfNumbers);

/*
* Função que verifica foi passado algum parâmetro na linha de comando
*/

int checkNumberOfArguments(int numberOfArguments);

/*
* Função que determina a ordenação do vetor
*/
void arrayTypeOrdenation(int lengh, int * arrayOfNumbers, char * type);

#endif
