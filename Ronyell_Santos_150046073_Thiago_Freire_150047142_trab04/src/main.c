#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libseno.h"

void displayNumero(char * opcao, double numero, double resultado);

double calculaResultado(char * opcao, double numero);

int main(int argc, char * argv[]){
double b = seno(96);
  printf("%.3lf\n", b);
  return 0;
}

void displayNumero(char * opcao, double numero, double resultado){
  int comparaOpcao = strcmp(opcao, SENO);
  if(!comparaOpcao){
    printf("arc_seno (%.3lf) = %lf\n", numero, resultado);
  }else{
    comparaOpcao = strcmp(opcao, ARC_SENO);
    if(!comparaOpcao){
      printf("seno (%.3lf) = %lf\n", numero, resultado);
    }else{
      printf("Opcao Inválida!!");
    }
  }
}
