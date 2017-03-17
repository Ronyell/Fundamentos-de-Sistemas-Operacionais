#include <stdio.h>
#include <stdlib.h>
#include "InputOutput.h"
#include "Operations.h"

/*
* Função que recebe todos os números
*/

int scanfAllNumbers(int * arrayOfNumbers){
  int lengh = 0;
  int aux = 0;
  do{
    scanf("%d",&aux );
    if(aux != -1){
      arrayOfNumbers[lengh] = aux;
      lengh++;
      arrayOfNumbers = arrayReallocation(lengh, arrayOfNumbers);
    }
  } while (aux != -1);

  return lengh;
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
