#ifndef COMPOUNDS_H
#define COMPOUNDS_H
#include <stdio.h>
#include <stdlib.h>

/*
* Estrutura relacionada ao ponto que é uma coordenada cartesiana
*/
  typedef struct {
    double x;
    double y;
  } Ponto;


/*
* Estrutura relacionada ao quadrilátero que são quatro retas ou quatro coordenadas cartesianas
*/

  typedef struct {
     Ponto ponto[4];
  } Quadrilatero;

#endif
