#include<stdio.h>
#include <math.h>
#define PI 3.14159265

void main()
{
    int i, n;
    float x, sum, t;

    //Número de interações para calcular a série, quanto maior menor o erro de seno.
    n = 10000;

    printf("Digite o angulo: ");
    scanf("%f",&x);
    t=x;
    sum=x;

    /* Loop to calculate the value of Sine */
    for(i=1;i<=n;i++)
    {
        t=(t*(-1)*x*x)/(2*i*(2*i+1));
        sum=sum+t;
    }
    printf("VALOR DE SENO: %f\n", sin(x));
    printf("Valor do seno em radianos: %.6f\n",sum);
}

