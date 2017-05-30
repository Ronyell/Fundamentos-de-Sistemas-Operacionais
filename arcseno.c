#include <stdio.h>
#include <math.h>

int main(){
  double resultado = 0;
  double resultadoF = 0;
  double x, x1, x2, x3, x4, x5, x6;

  scanf("%lf", &x);

  x1 = x;
  x2 = ((x*x*x)/3.0)*(1.0/2.0);
  x3 = (1.0/2.0)*(3.0/4.0)*((x*x*x*x*x)/3.0);
  x4 = (1.0/2.0)*(3.0/4.0)*(5.0/6.0)*((x*x*x*x*x*x*x)/3.0);
  x5 = (1.0/2.0)*(3.0/4.0)*(5.0/6.0)*(7.0/8.0)*((x*x*x*x*x*x*x*x*x)/3.0);
  //x6 = (1.0/2.0)*(3.0/4.0)*(5.0/6.0)*(7.0/8.0)*(9.0/10.0)*((x*x*x*x*x*x*x*x*x*x*x)/3.0);


  printf("x1: %lf\n", x1);
  printf("x2: %lf\n", x2);
  printf("x3: %lf\n", x3);
  printf("x4: %lf\n", x4);
  printf("x5: %lf\n", x5);
  printf("x6: %lf\n", x6);


  resultado = x1 + x2 + x3 + x4 + x5;

  printf("Meu arco seno: %lf", resultado);
  printf("Arco seno math.h: %lf", asin(x));
  return 0;
}
