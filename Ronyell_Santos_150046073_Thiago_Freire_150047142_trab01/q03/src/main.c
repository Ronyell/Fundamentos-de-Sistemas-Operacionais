#include <stdio.h>
#include <stdlib.h>
#include "Operations.h"
#include "InputOutput.h"

int main(int argc, char* argv[]){
  int lengh = 0;
  int * arrayOfNumbers = NULL;
  int typeOrdenation = 0;

  arrayOfNumbers = arrayAllocation();
  lengh = scanfAllNumbers(arrayOfNumbers);

  typeOrdenation = checkNumberOfArguments(argc);

  if(typeOrdenation && lengh){
    arrayTypeOrdenation(lengh, arrayOfNumbers, argv[1]);
  }else if(lengh){
    arrayCreasing(lengh, arrayOfNumbers);
  }

  printAllNumbers(lengh, arrayOfNumbers);

  free(arrayOfNumbers);

  return 0;
}
