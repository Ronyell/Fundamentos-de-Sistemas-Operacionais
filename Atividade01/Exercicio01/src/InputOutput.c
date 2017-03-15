#include <stdio.h>
#include <stdlib.h>
#include <Compounds.h>
#include <InputOutput.h>

/*
* Função que recebe um ponto (dois números)
*/

Point scanfPoint(){

  Point point = NULL;

  scanf("%lf",&point.x);
  scanf("%lf",&point.y);

  return point;
}


/*
* Função que recebe os pontos de um quadrilátero (quatro pontos, quatro retas, oito números)
*/

Points * scanfAllPoints(){

  Point points[4] = NULL;

  for(int i = 0; i<4; i++){

    points[i] = scanfPoint;

  }

  return points;
}
