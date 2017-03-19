#include <stdio.h>
#include <stdlib.h>
#include "Compounds.h"
#include "InputOutput.h"
#include "Operations.h"

/*
* Função que recebe um ponto (dois números)
*/

Ponto recebePonto(){

  Ponto ponto;

  scanf("%lf",&ponto.x);
  scanf("%lf",&ponto.y);

  return ponto;
}


/*
* Função que recebe os pontos de um quadrilátero (quatro pontos, quatro retas, oito números)
*/

Quadrilatero recebeTodosPontos(){

  Quadrilatero quadrilatero;
  int contador = 0;

  for(contador = 0; contador<4; contador++){

    quadrilatero.ponto[contador] = recebePonto();

  }

  return quadrilatero;
}

/*
* Função que imprime o tipo do quadrilatero
*/

void imprimeTipo(int tipo, Quadrilatero quadrilatero){
  if(tipo == 0){
    double area = 0.0;

    printf("Quadrilatero convexo.\n");

    area = calculaArea(quadrilatero);
    imprimeArea(area);
  }else{
    printf("Quadrilatero nao convexo.\n");
  }
}

/*
* Função que imprime a area do quadrilátero
*/

void imprimeArea(double area){
  printf("Area: %.2lf.\n",area);
}
