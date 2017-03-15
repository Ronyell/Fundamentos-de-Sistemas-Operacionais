#include <stdio.h>
#include <stdlib.h>

/*
* Estrutura relacionada ao ponto que é uma coordenada cartesiana
*/
  struct {
    double x;
    double y;
  } Point;

/*
* Estrutura relacionada a reta entre dois pontos ou duas coordenadas cartesianas
*/
  struct {
    Point points[2];
  } Line;

/*
* Estrutura relacionada ao quadrilátero que são quatro retas ou quatro coordenadas cartesianas
*/

  struct {
     Line lines[4];
  } Square;
