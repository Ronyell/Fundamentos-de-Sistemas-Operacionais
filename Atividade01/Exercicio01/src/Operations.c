#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Compounds.h"
#include "InputOutput.h"

/*
* Função que calcula o determinante entre os pontos
*/

double calculaDeterminante(Ponto pontoA, Ponto pontoB, Ponto pontoC){
  double determinante = 0.0;

  determinante = (pontoA.x * pontoB.y + pontoA.y * pontoC.x + pontoB.x * pontoC.y) / (pontoC.x * pontoB.y + pontoC.y * pontoA.x + pontoB.x * pontoA.y);

  return determinante;
}

/*
* Função que verifica se o quadrilatero é convexo
*/

int verificaConvexao(Quadrilatero quadrilatero){
      Ponto pontos[5];
      int contador = 0, orientacao = 0;

      for(contador = 0; contador < 5; contador++){
          if(contador<4){
            pontos[contador] = quadrilatero.ponto[contador];
          }else{
            pontos[contador] = quadrilatero.ponto[0];
          }
      }

      contador = 0;

      for (contador = 0; contador < 4; contador++){

          int determinante = calculaDeterminante(pontos[contador], pontos[contador + 1], pontos[contador + 2]);

          if (determinante == 0)
              continue;

          orientacao = determinante;
          break;
      }

      for (; contador < 4; contador++)
      {
          int determinante = calculaDeterminante(pontos[contador], pontos[contador + 1], pontos[contador + 2]);

          if (determinante == -orientacao)
              return 0;
      }

      return orientacao != 0;
}


/*
* Função que calcula a área de um polígono convexo
*/

double calculaArea(Quadrilatero quadrilatero){
    double area = 0.0, somaA = 0.0, somaB = 0.0;
    int contador = 0;

        for (contador = 0; contador < 4; contador++)
        {
            somaA = somaA + quadrilatero.ponto[contador].x * quadrilatero.ponto[contador + 1].y;
            somaB = somaB + quadrilatero.ponto[contador + 1].x * quadrilatero.ponto[contador].y;
        }

        area = fabs((somaA - somaB)/2.0);

        return area;
}
