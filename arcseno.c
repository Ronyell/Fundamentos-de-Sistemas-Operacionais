#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// double fatorial_duplo(double numero){
//   double resultado = numero;
//
//   if (numero <= 1){
//     resultado = 1;
//   } else {
//     while (number > 2) {
//       resultado *= (numero-2);
//       numero = numero - 2;
//     }
//   }
//
//   return resultado;
// }

int main(int argc, char * argv[]){
        double resultado = 0;
        double x, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, z, y;
        char seno[] = "-s";
        char arcseno[] = "-a";
        int verificaSeno = 0, verificaArcseno = 0;
        int i = 0;

        verificaSeno = strcmp(seno, argv[1]);
        verificaArcseno = strcmp(arcseno, argv[1]);
        x = atof(argv[2]);

        if(verificaSeno == 0) {
                printf("Função Seno: \n");
        } else if(verificaArcseno == 0) {
                printf("Função Arcseno: \n");


                for (int i = 0; i < 10; i++) {
                        int resultado1=1, resultado2=1;
                        y = 2*i-1;
                        resultado1 = y;
                        if(y<=1) {
                                resultado1=1;
                        }else{
                                while (y > 2) {
                                        resultado1 *= (y-2);
                                        y = y - 2;
                                }
                        }

                        z = 2*i;
                        resultado2 = z;
                        if(z<=1) {
                                resultado2=1;
                        }else{
                                while (z > 2) {
                                        resultado2 *= (z-2);
                                        z = z - 2;
                                }
                        }

                        resultado += (resultado1/resultado2)*(pow(x, 2*i+1)/(2*i+1));

                        resultado1 = 0;
                        resultado2 = 0;
                }

                printf("Meu arco seno: %lf\n", resultado);
                printf("Arco seno math.h: %lf\n", asin(x));

        } else {

        }

        return 0;
}
