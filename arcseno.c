#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char * argv[]){
  double resultado = 0;
  double x, x1, x2, x3, x4, x5, x6;
  char seno[] = "-s";
  char arcseno[] = "-a";
  int verificaSeno = 0, verificaArcseno = 0;

  verificaSeno = strcmp(seno, argv[1]);
  verificaArcseno = strcmp(arcseno, argv[1]);
  x = atof(argv[2]);

  if(verificaSeno == 0){
    printf("Função Seno: \n");
  } else if(verificaArcseno == 0){
    printf("Função Arcseno: \n");

    x1 = x;
    x2 = ((x*x*x)/3.0)*(1.0/2.0);
    x3 = (1.0/2.0)*(3.0/4.0)*((x*x*x*x*x)/3.0);
    x4 = (1.0/2.0)*(3.0/4.0)*(5.0/6.0)*((x*x*x*x*x*x*x)/3.0);
    x5 = (1.0/2.0)*(3.0/4.0)*(5.0/6.0)*(7.0/8.0)*((x*x*x*x*x*x*x*x*x)/3.0);

    resultado = x1 + x2 + x3 + x4 + x5;

    printf("Meu arco seno: %lf\n", resultado);
    printf("Arco seno math.h: %lf\n", asin(x));

  } else {

  }

  return 0;
}
