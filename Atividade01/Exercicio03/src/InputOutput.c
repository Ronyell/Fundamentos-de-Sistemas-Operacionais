#include <stdio.h>
#include <stdlib.h>
#include "InputOutput.h"

/*
* Função que recebe o tamanho do vetor
*/

int scanfLengh(){
  int lengh = 0;

  scanf("%d",&lengh);

  return lengh;
}

/*
* Função que recebe todos os números
*/

int scanfAllNumbers(int lengh, int * arrayOfNumbers){
  int count = 0;

  for(count = 0; count<lengh; count++){
    int aux = 0;

    scanf("%d",&aux );

    if(aux == -1){
      break;
    }

    arrayOfNumbers[count] = aux;
  }

  return count;
}

/*
* Função que imprime todos os números
*/

void printAllNumbers(int lengh, int * arrayOfNumbers){
  int count = 0;

  for(count  = 0; count<lengh; count++){
    printf("%d ", arrayOfNumbers[count]);
  }

  printf("\n");
  
}
