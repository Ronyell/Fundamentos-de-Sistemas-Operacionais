#include <stdio.h>
#include <stdlib.h>
#include <Compounds.h>
#include <InputOutput.h>

/*
* Função que organiza os pontos em um quadrilátero
*/

Square generateQuadrilateral(){

  Square square = NULL;
  int positionTwo = 3;
  Point points[4] = scanfAllPoints();

  for(int i = 0; i < 4; i++){

    square.lines[i].points[0] = points[i];

      if(positionTwo == 2){

        square.lines[0].points[1] = points[i];

      }else{

        square.lines[positionTwo-i].points[1] = points[i];

      }

    }

  return square;
}
