#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H
#include <stdio.h>
#include <stdlib.h>

/*
* Função que recebe o tamanho do vetor
*/

int scanfLengh();

/*
* Função que recebe todos os números
*/

int scanfAllNumbers(int lengh, int * arrayOfNumbers);


/*
* Função que imprime todos os números
*/

void printAllNumbers(int lengh, int * arrayOfNumbers);

#endif
