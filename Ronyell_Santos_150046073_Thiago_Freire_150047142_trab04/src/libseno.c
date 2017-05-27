#include <stdio.h>
#include <stdlib.h>
#include "libseno.h"


double seno(double angulo){
  int contador, numeroInteracoes;
  double soma, termo;

  //Número de interações para calcular a série, quanto maior menor o erro de seno.
  numeroInteracoes = 10000;
  termo = angulo;
  soma = angulo;

  /* Loop to calculate the value of Sine */
  for(contador=1; contador <= numeroInteracoes; contador++)
  {
    termo = ( termo * ( -1 ) * angulo * angulo ) / (2 * contador * ( 2 * contador + 1 ) ) * 1.0;
    soma = soma + termo;
  }
  return soma;
}

double arc_seno(double seno){
  return 3.0 + 5.0;
}
