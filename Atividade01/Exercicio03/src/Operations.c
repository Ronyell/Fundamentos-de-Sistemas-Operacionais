#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Operations.h"

/*
* Função que aloca espaço para o vetor
*/

int * arrayAllocation(){
  int * arrayOfNumbers  = NULL;
  arrayOfNumbers = (int *) malloc(sizeof(int));

  return arrayOfNumbers;
}

/*
* Função que realoca espaço para o vetor
*/

int * arrayReallocation(int lengh, int *arrayOfNumbers){
  arrayOfNumbers = (int *) realloc(arrayOfNumbers, (lengh + 1)*sizeof(int) );
  return arrayOfNumbers;
}

/*
* Função que organiza o vetor de forma crescente
*/


void arrayCreasing(int lengh, int * arrayOfNumbers){
  int count = 0;
  int swap = 1;
  lengh = lengh - 1;
  printf("Saida crescente:\n");

  while(swap){
    swap = 0;
    for(count = 0; count<lengh; count++){
      if(arrayOfNumbers[count] > arrayOfNumbers[count+1]){
        int auxiliar = arrayOfNumbers[count];
        arrayOfNumbers[count] = arrayOfNumbers[count+1];
        arrayOfNumbers[count+1] = auxiliar;
        swap = 1;
      }
    }
    lengh = lengh - 1;
  }
}


/*
* Função que organiza o vetor de forma decrescente
*/
void arrayDecreasing(int lengh, int * arrayOfNumbers){
  int count = 0;
  int swap = 1;
  lengh = lengh - 1;

  printf("Saida decrescente:\n");

  while(swap){
    swap = 0;
    for(count = 0; count<lengh; count++){
      if(arrayOfNumbers[count] < arrayOfNumbers[count+1]){
        int auxiliar = arrayOfNumbers[count];
        arrayOfNumbers[count] = arrayOfNumbers[count+1];
        arrayOfNumbers[count+1] = auxiliar;
        swap = 1;
      }
    }
    lengh = lengh - 1;
  }
}

/*
* Função que verifica foi passado algum parâmetro na linha de comando
*/
int checkNumberOfArguments(int numberOfArguments){
  if(numberOfArguments > 1){
    return 1;
  }
return 0;
}

/*
* Função que determina a ordenação do vetor
*/
void arrayTypeOrdenation(int lengh, int * arrayOfNumbers, char * type){
  int typeOfOdenation = 0;

  typeOfOdenation = strcmp(type,DECREASING);

  if(!typeOfOdenation){
    arrayDecreasing(lengh, arrayOfNumbers);
  }else{
    arrayCreasing(lengh, arrayOfNumbers);
  }

}
