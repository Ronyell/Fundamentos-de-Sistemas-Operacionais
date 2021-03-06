#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libseno.h>

#define SENO "-s"
#define ARC_SENO "-a"

void displayNumero(char * opcao, double numero);

int main(int argc, char * argv[]){

  if(argc > 2){
    double angulo;
    angulo = atof(argv[2]);
    displayNumero(argv[1], angulo);
  } else {
    printf("Quantidade de parâmetros inválidos.\n");
  }
        return 0;
}

void displayNumero(char * opcao, double numero){
        double resultado = 0;
        int comparaOpcao = strcmp(opcao, SENO);

        if(!comparaOpcao) {
                resultado = seno(numero);
                printf("seno (%.3lf) = %.3lf\n", numero, resultado);
        }else{
                comparaOpcao = strcmp(opcao, ARC_SENO);
                if(!comparaOpcao) {
                        resultado = arc_seno(numero);
                        printf("arc_seno (%.3lf) = %.3lf\n", numero, resultado);
                }else{
                        printf("Opcao Inválida!!");
                        exit(-1);
                }
        }
}
