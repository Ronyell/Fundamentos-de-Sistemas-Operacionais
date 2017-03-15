#include <stdio.h>
#include <stdlib.h>
#include "Operations.h"
#include "InputOutput.h"

int main(int argc, char* argv[]){
  int lengh = 0;
  int * arrayOfNumbers = NULL;

  lengh = scanfLengh();
  arrayOfNumbers = arrayAllocation(lengh);
  lengh = scanfAllNumbers(lengh, arrayOfNumbers);

  int typeOrdenation = 0;
  typeOrdenation = checkNumberOfArguments(argc);

  if(typeOrdenation){
    arrayTypeOrdenation(lengh, arrayOfNumbers, argv[1]);
  }else{
    arrayCreasing(lengh, arrayOfNumbers);
  }

  printAllNumbers(lengh, arrayOfNumbers);

  free(arrayOfNumbers);
}
